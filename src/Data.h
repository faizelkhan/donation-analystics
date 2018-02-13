#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iterator>

using namespace std;

struct indiv {
	string cmte_id;
	string name;
	string zip;
	double amt;
	int date;
	int yr;
	string other_id;
};

struct rcpt {
	string cmte_id;	//committe ID
	string zip; // Zip Code
	int yr; // Year
	vector<double> perc_amt; // Given Percentile amt 
	double total_amt; // 
	int num_contr;
};

class Data{
private:
	vector<indiv> allDonList;
	//vector<indiv> repDonList;
	//percentile list
	//amt for commtt list
	vector<rcpt> recList;

public:
	Data();
	// get
	vector<indiv> getAllDonList();
//	vector<indiv> getRepDonList();
	vector<rcpt> getRecList();
	double getRecPercAmt(string cmtid_par, double perc);
	vector<rcpt>::iterator getRecItr(string cmteid_par);

	bool isRepDonor(string name_par, string zip_par, int yr_par);// name_par - name parameter; zip_par - zip code parameter
//	bool lookRepDonor(string name_par, string zip_par);
	bool lookRcpt(string cmtid_par);

	// set/add
	void addADonor(indiv ind_par);
//	void addRepDonor(indiv rep_donor);
	void addRecepient(rcpt rcpt_par);
	void addRecAmt(string cmteid_par, double amt);

};
