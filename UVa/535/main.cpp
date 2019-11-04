#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define RADIUS 6378

map<string, int> str2id;
map<int, string> id2str;
vector<double> vet_lat, vet_longi;

double to_rad(double a)
{
    double res = a * M_PI / 180.0;
    while (res < 0)
    {
        res += 2 * M_PI;
    }
    return res;
}

// Returns the shortest distance on the sphere with radius "radius" between
// the points with azimuthal angles (longitude) f1 and f2
// from x axis and zenith angles (latitude) t1 and t2
// from z axis. All angles measured in radians.
// The algorithm starts by converting the spherical coordinates
// to cartesian coordinates so if that is what you have you can
// use only the two last rows. dx*radius is then the difference
// between the two points in the x direction and d*radius is the
// total distance between the points.
double spherical_distance(double f1, double t1,
                          double f2, double t2, double radius)
{
   double dx = sin(t2) * cos(f2) - sin(t1) * cos(f1);
    double dy = sin(t2) * sin(f2) - sin(t1) * sin(f1);
    double dz = cos(t2) - cos(t1);
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    return radius * 2 * asin(d / 2);
}

int main()
{
    string city;
    int id = 0;
    while (cin >> city, city != "#")
    {
        double lat, longi;
        cin >> lat >> longi;
        vet_lat.pb(lat);
        vet_longi.pb(longi);
        str2id[city] = id;
        id2str[id] = city;
        ++id;
    }

    string u, v;
    while (cin >> u >> v, u != "#")
    {
        cout << u << " - " << v << endl;
        if (str2id.count(u) == 0 || str2id.count(v) == 0)
            cout << "Unknown" << endl;
        else
        {
            double res = spherical_distance(to_rad(vet_longi[str2id[u]]),
                                            to_rad(vet_lat[str2id[u]]),
                                            to_rad(vet_longi[str2id[v]]),
                                            to_rad(vet_lat[str2id[v]]), RADIUS);
            cout << int(round(res)) << " km" << endl;
        }
    }
}