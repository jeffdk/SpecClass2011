/**
 * francois hebert, jun 2011
 *
 * top hat-like window function:
 * if xmin <= x <= xmax, return x
 * else, return 0
 *
 * @param x     input
 * @param xmin  lower cutoff of window
 * @param xmax  upper cutoff of window
 *
 */

double TopHatWindow(const double x, const double xmin, const double xmax); 
