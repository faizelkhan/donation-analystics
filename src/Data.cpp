#include "Data.h"

Data::Data() {
}

// getAllDonList: gets the list of all donors
vector<indiv> Data::getAllDonList() {
	return allDonList;
}

// getRecList: gets the list of all the repeated recipients
vector<rcpt> Data::getRecList() {
	return recList;
}

//getRecPercAmt: calulates the percentile amount
double Data::getRecPercAmt(string cmtid_par, double perc) {
	for (vector<rcpt>::iterator v_itr = recList.begin(); v_itr != recList.end(); v_itr++) {
		if (((*v_itr).cmte_id).compare(cmtid_par) == 0) {
			sort((*v_itr).perc_amt.begin(), (*v_itr).perc_amt.end());
			int listNum = static_cast<int> (round(perc *0.01* ((*v_itr).num_contr)));
			vector<double>::iterator itr = (*v_itr).perc_amt.begin();
			advance(itr, listNum-1);
			return *itr;	
		}
	}
	return -1;
}

//getRecItr : gets the iterator position of a particular recipient in <recList>
vector<rcpt>::iterator Data::getRecItr(string cmteid_par, string zip_par) {
	for (vector<rcpt>::iterator v_itr = recList.begin(); v_itr != recList.end(); v_itr++) {
		if (((*v_itr).cmte_id.compare(cmteid_par)== 0)&& (((*v_itr).zip).compare(zip_par) == 0)) {
			return (v_itr);
		}
	}

}


//isRepDonor: check if the given donor already exists in the <allDonList>
bool Data::isRepDonor(string name_par, string zip_par, int yr_par) {
	for (vector<indiv>::iterator v_itr = allDonList.begin(); v_itr != allDonList.end(); v_itr++) {
		if (((*v_itr).name.compare(name_par) == 0)&&((*v_itr).zip.compare(zip_par) == 0) && ((*v_itr).yr < yr_par)) {
			return true;
		}
	}

	return false;

}

//lookRcpt: check if the profile of repeated recipient already exists
bool Data::lookRcpt(string cmtid_par, string zip_par ) {
	//cout << "\nTo find: " << cmtid_par << endl;
	for (vector<rcpt>::iterator v_itr = recList.begin(); v_itr != recList.end(); v_itr++) {
		
		if ((((*v_itr).cmte_id).compare(cmtid_par) == 0) && (((*v_itr).zip).compare(zip_par) == 0)) {
			
			return true;
		}
	}

	return false;
}


// addADonor: adds a new donor to <allDonList>
void Data::addADonor(indiv ind_par) {
	
	allDonList.push_back(ind_par);
}

//addRecipient: adds a new recipient to <recList>
void Data::addRecepient(rcpt rcpt_par) {
	recList.push_back(rcpt_par);
}

//addRecAmpt: updates info for an existing profile of a repreated recipient
void Data::addRecAmt(string cmteid_par, string zip_par, double amt) {
			vector<rcpt>::iterator v_itr = getRecItr(cmteid_par, zip_par);
			(*v_itr).total_amt = (*v_itr).total_amt + amt;
			(*v_itr).num_contr += 1;
			(*v_itr).perc_amt.push_back(amt);
}
