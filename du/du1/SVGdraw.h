/* 
 * File:   SVGdraw.h
 * Author: Jaro Budis, Brona Brejova
 */

/** The SVGdraw library provides a simple interface 
 * for writing SVG files. This library 
 * was developed by Jaro Budis and Brona Brejova for teaching 
 * first-year course  Programming (1) in C/C++ 
 * at Comenius University in Bratislava.
 * 
 * See more information at the course webpage 
 * http://compbio.fmph.uniba.sk/vyuka/prog/
 */
#ifndef SVGDRAW_H
#define	SVGDRAW_H
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/** Class SVGdraw allows user to draw to a SVG file. 
 * Simple examples of use of this library can be found at 
 * http://compbio.fmph.uniba.sk/vyuka/prog/index.php/Predn%C3%A1%C5%A1ka_1 */
class SVGdraw {
public:
    /** Initialize SVG image with width w and height h and write it to
     * the specified filename.
     * Upper left corner coordinate is (0,0), lower-right corner (w,h). */
    SVGdraw(int width, int height, const char* filename);
    /** Animation will wait time seconds. */
    void wait(double time);
    /** All visible items in the animation will disappear */
    void clear();
    /** Hide item with selected id. Ids are returned by all
     * drawing functions (drawRectangle etc.) */
    void hideItem(int id);
    /** Finish writing image to file */
    void finish();
    ~SVGdraw();

    /** Draw a rectangle with upper left corner (x,y), width w, height h. 
     * Return value specifies item id for future delteion. */
    int drawRectangle(double x, double y, double width, double height);
    /** Draw an ellipse with center (x,y), x-axis radius rx, y-axis radius ry. */
    int drawEllipse(double x, double y, double rx, double ry);
    /** Draw line from (x1,y2) to (x2,y2). */
    int drawLine(double x1, double y1, double x2, double y2);
    /** Write the given text at position (x, y).
     * If justification is empty, text will be centered in both x and y.
     * If justification contains letter l, left border will be at x,
     * letter r means right border will be at x. Similarly letters b and t
     * mean that top or bottom will be at coordinate y. */
    int drawText(double x, double y, const char* text,
            const char* justification = "");

    /** Start a new polygonal path at position (x,y). 
     * After starting polygon, add more points by addPolygonPoint,
     * then draw by drawPolygon. */
    void startPolygon(double x, double y);
    /** Add a new point to the current polygon. */
    void addPolygonPoint(double x, double y);
    /** Draw the polygon specified by startPolygond and 
     * addPolygonPoint methods, then clear polygin coordinates. */
    int drawPolygon();

    /** Set line color to a given RGB value.
     * All three values should be between 0 and 255.
     * Line color is used for drawing lines and writing text. */
    void setLineColor(int r, int g, int b);
    /** Set line color to a given named color.
     * List of color names: http://www.w3.org/TR/SVG/types.html#ColorKeywords
     */
    void setLineColor(const char* color);
    /** Set fill color to a given RGB value. 
     * This color is used to fill in shapes. */
    void setFillColor(int r, int g, int b);
    /** Set fill color to a given named color. */
    void setFillColor(const char* color);
    /** Set fill to invisible color. */
    void setNoFill();
    /** Set size of the font (default is 12). */
    void setFontSize(double size);
    /** Set width of lines (default is 1). */
    void setLineWidth(double width);

protected:
    vector <pair<double, double> > itemTimes_;
    vector <pair<double, double> > polygon_;
    double time_;
    bool isActive_;
    ofstream svg_;
    int addItem();
    int nextItemId();
    void printStyle();
    string lineColor_;
    string fillColor_;
    double fontSize_;
    double lineWidth_;
};

/** Class Turtle allows user to create turtle graphics
 * in an SVG file. */
class Turtle {
public:
    /** Initialize SVG image and create a turtle. 
     * Image will have width w and height h and will be writen to
     * the specified filename. 
     * Turtle will start at position (x,y) heading at the given angle. 
     * With angle=0 turtle heads right, angle=90 heads up etc. */
    Turtle(int width, int height, const char* filename,
            int x, int y, double angle);
    /** Set turtle speed to given value.
     * Default is 100 distance units per second. */
    void setSpeed(double speed);
    /** Move furtle forward by distance d. */
    void forward(double length);
    /** Turn turtle left by the given angle (in degrees).  */
    void turnLeft(double angle);
    /** Turn turtle right by the given angle (in degrees).  */
    void turnRight(double angle);
    /** Move turtle to the specified location. */
    void goTo(double x, double y);

    /** Finish writing image to file */
    void finish();
    ~Turtle();
protected:
    double x_, y_, angle_;
    double pathLength_;
    double speed_;
    bool isActive_;
    ofstream svg_;
};

#endif	/* SIMPLEDRAW_H */
