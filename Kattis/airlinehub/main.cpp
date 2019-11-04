#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
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

#define M_PI 3.14159265358979323846

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
    double dx = cos(t2) * cos(f2) - cos(t1) * cos(f1);
    double dy = cos(t2) * sin(f2) - cos(t1) * sin(f1);
    double dz = sin(t2) - sin(t1);
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    return radius * 2 * asin(d / 2);
}

int main()
{
    ll n;
    while (scanf("%lld", &n) != EOF)
    {
        vector<pair<double, double>> vet_points(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &vet_points[i].fi, &vet_points[i].se);
        }

        double best_v = 1e9;
        int best_e;
        for (int i = 0; i < n; i++)
        {
            double max_dist = 0;
            for (int j = 0; j < n; j++)
            {
                max_dist = max(max_dist, spherical_distance(to_rad(vet_points[i].se), to_rad(vet_points[i].fi),
                                                            to_rad(vet_points[j].se), to_rad(vet_points[j].fi), 1));
            }

            if (max_dist <= best_v)
            {
                best_v = max_dist;
                best_e = i;
            }
        }

        printf("%.2lf %.2lf\n", vet_points[best_e].fi, vet_points[best_e].se);
    }
}