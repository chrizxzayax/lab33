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
#include "Car.h"


using namespace std;

const int DEFAULT_NUM_LANES = 4;
const int TOTAL_P = 20;
const int INITIAL_PER_LANE = 2;

const double PROB_PAY = 0.46;
const double JOIN_PROB = 0.39;
const double SWITCH_PROB = 0.15;

using Lane = deque<Car>;

void print_lane_queue(int lane_no, const Lane &lane) {
    cout << "Lane " << lane_no << " Queue:\n";
    if (lane.empty()) {
        cout << "    [empty]\n";
        return;
    }
    for (const auto &c : lane) {
        cout << "    ";
        c.print();
        cout << "\n";
    }
}

int pick_random_other_lane(int src, int num_lanes, mt19937 &rng) {
    uniform_int_distribution<int> dist(0, num_lanes - 2);
    int r = dist(rng);
    if (r >= src) return r + 1;
    return r;
}


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

    srand(static_cast<unsigned>(seed));
    mt19937 rng(seed ^ 0xA5A5A5A5u);
    uniform_real_distribution<double> prob_dist(0.0, 1.0);

    cout << "Simulation seed: " << seed << " num_lanes=" << num_lanes << " periods=" << total_p << " seed=" << seed << "\n\n";

    vector<Lane> lanes(num_lanes);// create vector of lanes
    for (int i = 0; i < num_lanes; ++i) {
        for (int j = 0; j < INITIAL_PER_LANE; ++j) {
            lanes[i].emplace_back();// add Car to lane
        }
    }
    // print initial lane queues
    cout << "Initial lane queues:\n";
    for (int i = 0; i < num_lanes; ++i) {
        cout << "Lane " << (i+1) << ":\n";
        for (const auto &c : lanes[i]) {
            cout << "    ";
            c.print();// print car
            cout << "\n";
        }
    }
}