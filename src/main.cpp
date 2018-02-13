#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Data.h"
#include "split.h"

using namespace std;

int main(){
	
	ifstream fin; //file input stream to read in donation information 
	ifstream fperc; //file input stream to read in percentile
	ofstream fout; //file output stream to write out the analysis 
	
	fin.open("./input/itcont.txt");
	if (fin.fail()) {
		cout << "File couldn't be opened!! Pease check the destination.";
		exit(1);
	}

	fperc.open("./input/percentile.txt");
	if(fperc.fail()){
		cout<<"File couldn't be opened!! Pease check the destination.";
		exit(1);
	}
	
	fout.open("./output/repeat_donors.txt");
	if (fout.fail()) {
		cout << "File couldn't be opened!! Pease check the destination.";
		exit(1);
	}
	
	string indv_info; 
	indiv temp_indv;
	rcpt temp_rcpt;
	Data data1 = Data();
	double perc;
	fperc>>perc;
	int count , count_num = 0;
	bool checkSpace = false;
	vector<string> listOfStr;
	
	//read in lines until the pointer reaches the end
	while (!fin.eof()) {
		count = 0;
		checkSpace = false;
		//read line
		getline(fin,indv_info);
		//check if it's an empty line
		if (indv_info.length() > 0) {
			//separate all the columns
			listOfStr = split(indv_info, delim);
			//access each string of the vector
			for (vector<string>::iterator v_itr = listOfStr.begin(); v_itr != listOfStr.end(); v_itr++) {
				//count the column number
				count++;
				//get the required info
				switch (count) {
				case 1:
					//committee id
					if((*v_itr).compare(" ") != 0){
						temp_indv.cmte_id = *v_itr;
					}else{
						checkSpace = true;
					}
					cout<<". ";
					break;
				case 8:
					//individual name
					if(((*v_itr).compare(" ") != 0)&& ((*v_itr).length() > 1)){
						temp_indv.name = *v_itr;
					}else{
						
						checkSpace = true;
					}
					cout<<". ";
					break;
				case 11:
					//zip code of donor's place
					if(((*v_itr).compare(" ") != 0) && ((*v_itr).length() > 0)){
						temp_indv.zip = (*v_itr).substr(0, 5);
					}else{
						
						checkSpace = true;
					}
					cout<<". ";
					break;
				case 14:
					//transaction date
					if(((*v_itr).compare(" ") != 0)&& ((*v_itr).length() == 8)){
						temp_indv.date = stoi(*v_itr);
						temp_indv.yr = stoi((*v_itr).substr(4, 4));
					}else{
						
						checkSpace = true;
					}
					cout<<". ";
					break;
				case 15:
					//donation amount
					if((*v_itr).compare(" ") != 0){
						temp_indv.amt = stod(*v_itr);
						if(temp_indv.amt <= 0){
							checkSpace = true;
						}
					}else{
						
						checkSpace = true;
					}
					cout<<". ";
					break;
				case 16:
					//receiver type
					if((*v_itr).compare(" ") != 0){
						temp_indv.other_id = *v_itr;
						checkSpace = true;
					}
					else{
						
						temp_indv.other_id = "NULL";
					}
					cout<<". ";
					break;
				}
				
			}
			
			//look for donor
			if (data1.isRepDonor(temp_indv.name, temp_indv.zip, temp_indv.yr) && !checkSpace) {
				
				//look for recipient
				if(!data1.lookRcpt(temp_indv.cmte_id, temp_indv.zip)){
					
					temp_rcpt.cmte_id = temp_indv.cmte_id;
					fout<<temp_rcpt.cmte_id<<"|";
					temp_rcpt.zip = temp_indv.zip;
					fout <<temp_rcpt.zip<<"|";
					temp_rcpt.yr = temp_indv.yr;
					fout <<temp_rcpt.yr<<"|";
					temp_rcpt.perc_amt.push_back(temp_indv.amt);
					fout << temp_indv.amt<<"|";
					temp_rcpt.total_amt = temp_indv.amt;
					fout << temp_rcpt.total_amt<<"|";
					temp_rcpt.num_contr = 1;
					fout <<temp_rcpt.num_contr<<endl;
					data1.addRecepient(temp_rcpt);
				}
				//add recipient 
				else {
					
					data1.addRecAmt(temp_indv.cmte_id, temp_indv.zip,temp_indv.amt);
					vector<rcpt>::iterator rcpt_itr = data1.getRecItr(temp_indv.cmte_id, temp_indv.zip);					
					fout << (*rcpt_itr).cmte_id << "|";
					fout << (*rcpt_itr).zip << "|";
					fout << (*rcpt_itr).yr << "|";
					fout << data1.getRecPercAmt((*rcpt_itr).cmte_id, perc)<<"|";
					fout << (*rcpt_itr).total_amt<<"|";
					fout << (*rcpt_itr).num_contr << endl;
					
				}
			}
			
			else if(!checkSpace) {
				
				data1.addADonor(temp_indv);
				
			}
			
		}
		count_num++;
		system("CLS");
	}

	fin.close();
	fout.close();
	
}
