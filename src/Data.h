#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iterator>

using namespace std;

//Define object type for individuals
struct indiv {
	string cmte_id;
	string name;
	string zip;
	double amt;
	int date;
	int yr;
	string other_id;
};

//Define object type for object recipient
struct rcpt {
	string cmte_id;	//committe ID
	string zip; // Zip Code
	int yr; // Year
	vector<double> perc_amt; // Given Percentile amt 
	double total_amt; // 
	int num_contr;
};

//Define an object for database, where all the information is stored
class Data{
private:
	vector<indiv> allDonList; //All of the donors are saved in this list
	vector<rcpt> recList; // Recipient information of repreated donation are stored in this list

public:
	Data(); // Constructor
	
	// getAllDonList: gets the list of all donors
	vector<indiv> getAllDonList();
	
	// getRecList: gets the list of all the repeated recipients
	vector<rcpt> getRecList();
	
	//getRecPercAmt: calulates the percentile amount
	double getRecPercAmt(string cmtid_par, double perc);
	
	//getRecItr : gets the iterator position of a particular recipient in <recList>
	vector<rcpt>::iterator getRecItr(string cmteid_par, string zip_par);
	
	//isRepDonor: check if the given donor already exists in the <allDonList>
	bool isRepDonor(string name_par, string zip_par, int yr_par);// name_par - name parameter; zip_par - zip code parameter
	
	//lookRcpt: check if the profile of repeated recipient already exists
	bool lookRcpt(string cmtid_par, string zip_par);

	// addADonor: adds a new donor to <allDonList>
	void addADonor(indiv ind_par);
	
	//addRecipient: adds a new recipient to <recList>
	void addRecepient(rcpt rcpt_par);
	
	//addRecAmpt: updates info for an existing profile of a repreated recipient
	void addRecAmt(string cmteid_par, string zip_par, double amt);

};
