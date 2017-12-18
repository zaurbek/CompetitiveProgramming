
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> dd;

dd solve(dd a, dd b, dd c, dd d) {
	double dx1 = b.first-a.first;
	double dy1 = b.second-a.second;
	double m1 = (fabs(dx1)>1e-9?dy1/dx1:DBL_MAX);
	double c1 = a.second-m1*a.first;

	double dx2 = d.first-c.first;
	double dy2 = d.second-c.second;
	double m2 = (fabs(dx2)>1e-9? dy2/dx2:DBL_MAX);
	double c2 = c.second-m2*c.first;

	dd inter = {DBL_MAX, DBL_MAX};
	
	if(m2==DBL_MAX && m1==DBL_MAX) {
		//both vertical
		return inter;
	} else if (m2==DBL_MAX) {
		//second is vertical, first is not (maybe 0)
		inter.first = c.first; 
		inter.second = m1*c.first + c1;
		return inter;
	} else if (m1==DBL_MAX){
		//first is vertical, second is not (maybe 0)
		inter.first = a.first; 
		inter.second = m2*a.first + c2;
		return inter;
	}

	if(fabs(m1-m2)<1e-9) { //are equal
		return inter;
	} else { //are not equal
		inter.first = (c2-c1)/(m1-m2);
		inter.second = m2*inter.first+c2;
		cout<<inter.second<<' '<<c1<<' '<<c2<<'\n';
		return inter;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--) {
		double x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%lf %lf",&x1, &y1);
		scanf("%lf %lf",&x2, &y2);
		scanf("%lf %lf",&x3, &y3);
		scanf("%lf %lf",&x4, &y4);
		if( fabs((y2-y1)*(x3-x2)-(y3-y2)*(x2-x1))<1e-9 )
			printf("LINE\n");
		else {
			dd isection = solve({x1,y1},{x2,y2},{x3,y3},{x4,y4});
			if(isection.first==DBL_MAX&&isection.second==DBL_MAX)
				printf("NONE\n");
			else
				printf("POINT %.2lf %.2lf\n",isection.first+0.0, isection.second+0.0);
		}
	}
	printf("END OF OUTPUT");
}