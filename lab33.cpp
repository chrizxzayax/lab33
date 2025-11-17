// // comsc 210 | lab33 | Christian Molina

#include <iostream>
#include <deque>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
#include <cstdlib>


using namespace std;

const int DEFAULT_NUM_LANES = 4;
const int TOTAL_P = 20;
const int INITIAL_PER_LANE = 2;

const double PROB_PAY = 0.46;
const double JOIN_PROB = 0.39;
const double SWITCH_PROB = 0.15;


int main(int argc, char** argv){

    unsigned seed = (unsigned) time(nullptr);

    int total_p = TOTAL_P;
    int num_lanes = DEFAULT_NUM_LANES;
    if ( argc >= 2) {
        try { seed = static_cast<unsigned>(stoul(string(argv[1]))); } catch(...) {}
    }
    if (argc >= 3) {
        try { total_p = stoi(string(argv[2])); if (total_p < 1) total_p = TOTAL_P; } catch(...) {}
    }
    if (argc >= 4) {
        try { num_lanes = stoi(string(argv[3])); if (num_lanes < 1) num_lanes = DEFAULT_NUM_LANES; } catch(...) {}
    }

    srand<lane> lanes(num_lanes)
}