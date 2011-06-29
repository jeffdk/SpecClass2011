/**
 * Ensures that quantities do not exceed some maximum value.  If the quantity
 * is less than the maximum value, returns that quantity; otherwise, returns
 * its maximum allowed value.
 *
 * @param x     the quantity to impose a cap on
 * @param max   the largest value that may be returned
 * @return      the capped quantity
 */
double ImposeCap(const double x, const double max);
