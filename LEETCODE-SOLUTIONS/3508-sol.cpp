struct Packet {
    int source;
    int destination;
    int timestamp;

    bool operator==(const Packet& other) const {
        return source == other.source && destination == other.destination && timestamp == other.timestamp;
    }

    struct Hash {
        size_t operator()(const Packet& p) const {
            return hash<int>()(p.source) ^ hash<int>()(p.destination) ^ hash<int>()(p.timestamp);
        }
    };
};

class Router {
private:
    int memoryLimit;
    unordered_set<Packet, Packet::Hash> uniquePackets;
    queue<Packet> packetQueue;
    unordered_map<int, vector<int>> destinationTimestamps;
    unordered_map<int,int> map ;


public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet packet{source, destination, timestamp};
        if (uniquePackets.find(packet) != uniquePackets.end()) {
            return false; // Duplicate packet
        }
        if (packetQueue.size() == memoryLimit) {
            forwardPacket(); // Remove oldest packet
        }
        packetQueue.push(packet);
        uniquePackets.insert(packet);
        destinationTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packetQueue.empty()) {
            return {}; // No packet to forward
        }
        Packet packet = packetQueue.front();
        packetQueue.pop();
        map[packet.destination]++ ;
        uniquePackets.erase(packet);
        return {packet.source, packet.destination, packet.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (destinationTimestamps.find(destination) == destinationTimestamps.end()) {
            return 0;
        }
        const vector<int>& timestamps = destinationTimestamps[destination];
        auto lower = lower_bound(timestamps.begin() + map[destination], timestamps.end(), startTime);
        auto upper = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return (upper - lower) > 0 ? upper-lower : 0;
    }
};