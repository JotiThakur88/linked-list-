class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> mp; // tokenId -> expiryTime

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId] > currentTime) {
            mp[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto &it : mp) {
            if (it.second > currentTime) {
                count++;
            }
        }
        return count;
    }
};