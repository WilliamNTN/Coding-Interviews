// An H-tree is a geometric shape that consists of a repeating pattern
// resembles the letter "H"
// It can be constructed by starting with a line segment of arbitrary length,
// drawing two segments of the same length at right angles to the first through
// its endpoints, and continuing in the same vein, reducing the length of
// the line segments draw at each stage by sqrt(2);

//img:  https://www.pramp.com/img/content/img04.png
// The problem consists in writing a function that constructs an H tree, given
// its center x y, a starting length and a depth.
// Assumes that a function "drawLine" would draw a line from point 1 (x1,y1)
// and 2 (x2,y2);

//The solution is, given an center, call drawLine for each line, and then
// call a recursion for each extreme point of the H draw.

#include <iostream>

void drawLine(double x1, double y1, double x2, double y2) {
    // draw a line from (x1,y1) to (x2,y2);
}

// Time complexity = O(n^depth), where n = number of extremity points
// of the pattern. "H" has 4, so n = 4.

//Space Complexity = O (depth), as the number of functions at the stack
// at the same instant will be a unic branch of the recursion tree.

void HTreeConstruction(double centerx, double centery, int depth,double len){
  if(depth == 0) return;
  double leftX = (centerx-len/2);
  double rightX = (centerx + len/2);
  double topY = (centery + len/2);
  double botY = (centery - len/2);

  drawLine(leftX,centery, rightX,centery); // middle line
  drawLine(leftX,topY,leftX,botY);         // left line
  drawLine(rightX,topY,rightX,botY);        //right line

  // recursive for each extremity
  HTreeConstruction(leftX,topY,depth-1,(len/sqrt(2)));
  HTreeConstruction(leftX,botY,depth-1,(len/sqrt(2)));
  HTreeConstruction(rightX,topY,depth-1,(len/sqrt(2)));
  HTreeConstruction(rightX,botY,depth-1,(len/sqrt(2)));

  return;
}



int main()
{
    return 0;
}
