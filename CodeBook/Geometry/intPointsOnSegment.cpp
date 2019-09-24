/*
	count all border integer points in a polygon
*/

int border_pts(vii &poly)
{
	int total = 0;
	for (int i = 1; i < (int)poly.size(); i++)
	{
		total += __gcd(abs(poly[i].x - poly[i - 1].x), abs(poly[i].y - poly[i - 1].y));
	}
	total += __gcd(abs(poly.front().x - poly.back().x), abs(poly.front().y - poly.back().y));
	return total;
}
