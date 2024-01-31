void loadData()
{
// get model number the user wants to use 
int model;
cout << "Enter model number (1 or 2): " << endl; 
cin >> model;
if(model == 1)
data::Load("../data/reference1.csv", referenceData, true);
// dataset for model 1
else if (model == 2)
data::Load("../data/reference2.csv", referenceData, true);
// dataset for model 2
else
cout << "Invalid model number" << endl;
data::Load(“../data/query.csv”, queryData, true);
}
