// Implementation of Fractional Knapsack Problem.
#include <iostream> 
#include <vector>
#include <algorithm> // sort().
#include <iterator>  

using namespace std;

bool comparator(const pair<int, float> &a, 
               const pair<int, float> &b) 
{ 
    return (a.second > b.second); 
} 

int main()
{
	int n;             // Number of datasets.
	float c, wtx, ptx;               // c is size of knapsack.
	vector<float> wt, pt;  
	vector<pair<int, float> >vec;
	
	cout<<"Enter the size of your Knapsack : ";
	cin>>c;
	cout<<"Enter the size of your dataset : ";
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cout<<"Enter the weight and profit, respectively, of "<<i+1<<"th element of the dataset :"<<endl;
		cin>>wtx>>ptx;
		
		wt.push_back(wtx);
		pt.push_back(ptx);
		vec.push_back(make_pair(i, (pt.at(i)/wt.at(i)) ) );
	}
	
	sort(vec.begin(), vec.end(), comparator);

	int i = 0;
	float profit = 0, weight = 0;
	vector<float> fraction_x;
	
	while(weight < c)
	{
		if(weight + wt.at(vec[i].first) <= c)
		{
			fraction_x.push_back(1);                  //Placing the complete element in the knapsack.
			weight = weight + wt.at(vec[i].first);
		}
		else
		{
			float lastfill = (c - weight)/(wt.at(vec[i].first)); 
			fraction_x.push_back(lastfill);           //Placing only a fraction of element
			weight = c;
		}
		profit = profit + pt.at(vec[i].first)*fraction_x.at(i);   // Calculating the total profit.
		i++;
	}
	
	cout<<"Maximum profit for the given Knapsack is "<<profit<<endl;
	
	return 0;
}










