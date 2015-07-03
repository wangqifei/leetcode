// 149 Max Points on a Line
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

// Hide Tags Hash Table Math


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 #include <unordered_map>
 #include <vector>
 #include <iostream>
 using namespace std;

 struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        unordered_map<double, int> mp;
        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            mp.clear();
            double s = 0;
            int max_point_num = 1; //Caution, this variable init the number of the point on the same line. at least the current points[i] is the one on the line, therefore, it is set to 1
            int same_point = 0;
            for(int j = i+1; j < points.size(); ++j) {
                s = std::numeric_limits<double>::infinity();
                if(points[i].x != points[j].x) {
                    s = 1.0f*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                }
                else {
                    if(points[i].y == points[j].y) {
                        same_point++;
                        continue;
                    }
                }
                if(mp.count(s)) {
                    mp[s]++;
                }
                else {
                    mp.insert(make_pair(s, 2));
                }
                if(mp[s] > max_point_num) max_point_num = mp[s];
            }
            if(max_point_num+same_point > res) {
                res = max_point_num+same_point;
            }
        }
        return res;
    }
    //this function needs redefine the hash function with the pair<double, double> key, does not work
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        unordered_map<int, vector<Point> > mp1;
        unordered_map<pair<double, double>, vector<Point> > mp;
        double y1 = points[0].y;
        double x1 = points[0].x;
        double y2 = points[1].y;
        double x2 = points[1].x;
        double s = double(y2-y1)/(x2-x1);
        double d = double(x2*y1-y2*x1)/(x2-x1);
        int max_points = 2;
        double sth = 1e-2;
        double dth = 1e-2;
        mp.insert(make_pair(make_pair(s,d), vector<Point>({points[0], points[1]})));
        for(int i = 2; i < points.size(); ++i) {
            for(auto mit:mp) {
                double rs = mit.first.first;
                double rd = mit.first.second;
                for(auto vit:mit.second) {
                    x1 = vit.x;
                    y1 = vit.y;
                    x2 = points[i].x;
                    y2 = points[i].y;
                    double cs = double(y2-y1)/(x2-x1);
                    double cd = double(x2*y1-y2*x1)/(x2-x1);
                    if(abs(cs-rs)<sth && abs(cd-rd)<dth) {
                        vit.push_back(points[i]);
                        if(vit.size() > max_points) {
                            max_points = vit.size();
                        }
                    }
                    else {
                        mp.insert(make_pair(make_pair(cs,cd), vector<Point>({vit, points[i]})));
                    }
                }
            }
        }
        return max_points;
    }
};

int main(int argc, char const *argv[])
{
    int x[] = {1,2,3};
    int y[] = {4,5,6};
    int len = 3;
    vector<Point> points;
    for(int i = 0; i < len; ++i) {
        points.push_back(Point(x[i], y[i]));
    }
    Solution mySolution;
    int res = mySolution.maxPoints(points);
    cout<<res<<endl;
    return 0;
}