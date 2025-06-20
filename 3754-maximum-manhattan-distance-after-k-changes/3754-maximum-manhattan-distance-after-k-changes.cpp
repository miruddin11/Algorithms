typedef vector < int > vi;
typedef pair < int, int > pii;

class Solution {
  private: void updateCounts(char direction, int & east, int & west, int & north, int & south) {
    if (direction == 'E') east++;
    else if (direction == 'W') west++;
    else if (direction == 'N') north++;
    else if (direction == 'S') south++;
  }

  int calculateMaxDistance(int primary, int secondary, int k) {
    return primary + 2 * min(k, secondary);
  }

  int determineBestOption(int e, int w, int n, int s, int k, int index) {
    int northEast = (e + n) - (w + s);
    int southWest = (w + s) - (e + n);
    int northWest = (w + n) - (e + s);
    int southEast = (e + s) - (w + n);

    int bestOption = max({
      calculateMaxDistance(northEast, w + s, k),
      calculateMaxDistance(southWest, e + n, k),
      calculateMaxDistance(northWest, e + s, k),
      calculateMaxDistance(southEast, w + n, k)
    });

    return min(max(bestOption, 0), index + 1);
  }

  public: int maxDistance(string s, int k) {
    int east = 0, west = 0, north = 0, south = 0, maxDist = 0;

    for (int i = 0; i < s.size(); i++) {
      updateCounts(s[i], east, west, north, south);
      maxDist = max(maxDist, determineBestOption(east, west, north, south, k, i));
    }

    return maxDist;
  }
};