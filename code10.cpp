void load_query_data()
{
ifs
ifstream ifs("../data/query.json"); // loads the json file into 
string s;
try {
nlohmann::json jmsg = nlohmann::json::parse(ifs); // parses the json
auto &readings = jmsg["Reading"]; // readings stores the data present under the "Reading" class in the json
int array[number_of_sensors]; //buffer array
for (int sensor_number = 0; sensor_number < number_of_sensors; sensor_number++) { // stores the parsed sensor data in the buffer
s = "Sensor"+to_string(sensor_number+1);
array[sensor_number] = readings[s];
}
arma::mat row_major(1,number_of_sensors,arma::fill::zeros);
// 1 because 1 reading
for (int i = 0; i < number_of_sensors; i++) { // stores the data in the row major matrix from the buffer
row_major(0,i) = array[i];
}
query_data = row_major.t(); // transposes the row major matrix to a column major matrix for mlpack to use
}
catch (nlohmann::json::parse_error &e) // catches exceptions while parsing
{
cerr << e.what() << endl;
}
}