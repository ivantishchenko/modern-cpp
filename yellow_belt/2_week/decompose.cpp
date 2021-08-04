#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  string op_code;
  cin >> op_code;

  if(op_code == "NEW_BUS") {
	  q.type = QueryType::NewBus;

	  cin >> q.bus;

	  int stop_count;
	  cin >> stop_count;

      vector<string>& stops = q.stops;
      stops.resize(stop_count);
      for (string& stop : stops) {
        cin >> stop;
      }
  }
  else if(op_code == "BUSES_FOR_STOP") {
	  q.type = QueryType::BusesForStop;
	  cin >> q.stop;
  }
  else if(op_code == "STOPS_FOR_BUS") {
	  q.type = QueryType::StopsForBus;
	  cin >> q.bus;
  }
  else if(op_code == "ALL_BUSES") {
	  q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.empty()) {
		os << "No stop" << endl;
	} else {
		for (const string& bus : r.buses) {
			os << bus << " ";
		}
		os << endl;
	}
	return os;
}

struct StopsForBusResponse {
	vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if(r.stops.empty()) {
		os << "No bus" << endl;
	}
	else {
		for(const auto& [stop, bus_vector] : r.stops) {
			os << "Stop " << stop << ": ";
			for(const string& bus : bus_vector) {
				os << bus << " ";
			}
			os << endl;
		}

	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses_map;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if(r.buses_map.empty()) {
		os << "No buses" << endl;
	}
	else {
		for (const auto& [bus, stops] : r.buses_map) {
			os << "Bus " << bus << ": ";
			for (const string& stop : stops) {
				os << stop << " ";
	        }
	        os << endl;
		}
	}
	return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
	  _buses_to_stops[bus] = stops;

      for (const string& stop : stops) {
        _stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	if(_stops_to_buses.count(stop) == 0) return {};

	return {_stops_to_buses.at(stop)};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  StopsForBusResponse resp;
	  if (_buses_to_stops.count(bus) == 0) return resp;

	  for (const string& stop : _buses_to_stops.at(bus)) {
		  pair<string, vector<string>> stop_pair;
		  stop_pair.first = stop;

		  if (_stops_to_buses.at(stop).size() == 1) {

			  stop_pair.second.push_back("no interchange");
		  } else {
			  for (const string& other_bus : _stops_to_buses.at(stop)) {
				  if (bus != other_bus) {
					  stop_pair.second.push_back(other_bus);
				  }
			  }
		  }

		  resp.stops.push_back(stop_pair);
	  }
	  return resp;
  }

  AllBusesResponse GetAllBuses() const {
    return {_buses_to_stops};
  }

private:
  map<string, vector<string>> _buses_to_stops, _stops_to_buses;
};


int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
