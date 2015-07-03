// 223 Rectangle Area Total Accepted: 1446 Total Submissions: 5359 My Submissions Question Solution 
// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.
#include <iostream>
using namespace::std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width = 0;
        int height = 0;
        if(A<E) {
            if(C<=E) width = 0;
            else if(C<=G) width = C-E;
            else width = G-E;
        }
        else {
            if(A>=G) width = 0;
            else if(G>=A) width = G-A;
            else width = C-A;
        }
        if(B<F) {
            if(D<=F) width = 0;
            else if(D<=H) width = D-F;
            else width = H-F;
        }
        else {
            if(B>=H) width = 0;
            else if(H>=B) width = H-B;
            else width = D-B;
        }
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        int area3 = height*width;
        cout<<area1<<" "<<area2<<" "<<area3<<" "<<endl;
        return area1+area2-area3;
    }

    int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C-A)*(D-B);
        int s2 = (G-E)*(H-F);
        if(E>=C || G<=A || F>=D || H<=B) return s1+s2;
        return s1+s2-(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
    }

    //the same idea, but easier to understand
    int computeArea3(int A, int B, int C, int D, int E, int F, int G, int H) {
        int h = 0;
        int w = 0;
        if(min(C, G) > max(A, E)) w = min(C, G) - max(A, E);
        if(min(D, H) > max(B, F)) h = min(D, H) - max(B, F);
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        return area1+area2-h*w;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    // int A = -2, B = -2, C = 2, D = 2, E = -2, F = -2, G = 2, H = 2;
    int A = 0, B = 0, C = 0, D = 0, E = -1, F = -1, G = 1, H = 1;
    int res = mySolution.computeArea2(A, B, C, D, E, F, G, H);
    cout<<res<<endl;
    return 0;
}