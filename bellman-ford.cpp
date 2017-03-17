#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest, cost;
};

int main(){
	clock_t t;

	int T;
	cin>>T;
	while(T--){
		int v;
		int e;
		int src;
		cout<<"Enter Number of vertices and edges";
		cin>>v>>e;
		cout<<"Enter source vertex";
		cin>>src;
		Edge *edge;
		edge = new Edge[e];
		for(int i=0;i<e;i++){
			cin>>edge[i].src;
			cin>>edge[i].dest;
			cin>>edge[i].cost;
		}

		t=clock();

		int *dist;
		dist = new int[v];
		for(int i=0;i<v;i++){
			dist[i]=INT_MAX;
		}
		dist[src]=0;
		int a,b,c,check;
		for(int i=0;i<v;i++){
			for(int j=0;j<e;j++){
				a=edge[j].src;
				b=edge[j].dest;
				c=edge[j].cost;
				if(dist[a] != INT_MAX){
					if(dist[b] > (dist[a]+c)){
						if(i==v-1){
							check=1;
						}
						else{
							dist[b] = dist[a]+c;
						}
					}
				}
			}
		}
		if(check==1){
			cout<<"Negative cycle\n";
		}
		else{
			cout<<"\nDistance of all vertices from the source vertex:\n";
			cout<<"Vertex   Distance from source\n";
			for(int i=0;i<v;i++){
				cout<<i<<"          ";
				if(dist[i]==INT_MAX){
					cout<<"inf"<<endl;
				}
				else{
					cout<<dist[i]<<endl;	
				} 
			}
			cout<<endl;
		}

		t = clock() - t;
		printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);	
	}
	return 0;
}