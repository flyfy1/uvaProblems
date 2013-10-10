/*
Problem ID: 186
Solver: songyy
Start Time: 2011-4-1 12:21:51 
End Time:
Time Spent:
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>


using namespace std;

char temp[10000];
int edgeNameTable[100][100];
int graph[100][100];
int former[100][100];	// the former elements
int p[100][100];
vector<string> cityName;
vector<string> edgeName;
vector<int> edgeWeight;


void backTrack(int u,int v){
	if(p[u][v]!=u){
		backTrack(u,p[u][v]);
	}
	
	/*
	cout << 
		setw(20) << left << cityName[p[u][v]] << " " << 
		setw(20) << left << cityName[v] << " " << 
		setw(10) << left << edgeName[edgeNameTable[p[u][v]][v]] << " " << 
		setw(5) << right << edgeWeight[edgeNameTable[p[u][v]][v]] << endl;
	*/
	printf("%-20s %-20s %-10s %5d\n",cityName[p[u][v]].c_str(),cityName[v].c_str(),
		edgeName[edgeNameTable[p[u][v]][v]].c_str(),
		edgeWeight[edgeNameTable[p[u][v]][v]]);
}

void query(int u,int v){	

	printf("From                 To                   Route      Miles\n");
	printf("-------------------- -------------------- ---------- -----\n");
	
	backTrack(u,v);
	
	printf("                                                     -----\n");
	printf("                                          Total%11d\n",graph[u][v]);
}



int main(){
	freopen("186_in.txt","r",stdin);
//	freopen("186_out.txt","w",stdout);

	
	vector<string>::iterator it;
	
	// the index is the actual index in the map

	string aName,bName;
	string s_t;
	char *cps;
	int n=0,V;	// n edges, V cities
	int i,j;
	int u,v,w;
	
	// initialization
	// * the graph, set the mex weight to 100,000 (cuz all sums are less than 2^16 = 65536)
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			graph[i][j] = 100000;	// the graph table for compute
			former[i][j] = i;		// the former table for the path lookup
		}
	}
	
	n = 0;
	for(i=0;fgets(temp,10000,stdin);i++){
		if(temp[0]=='\n')	break;
		
		// compute the starting city - u
		aName = strtok(temp,",");
		if(cityName.empty()){
			cityName.push_back(aName);
			u = 0;
		}
		else{
			it = find(cityName.begin(),cityName.end(),aName);
			//cout << "aName: " << aName << endl;
			if(it == cityName.end()){
				cityName.push_back(aName);
			}
			u = it - cityName.begin();
		}	
		
			
		// compute the starting city - v
		bName = strtok(NULL,",");
		it = find(cityName.begin(),cityName.end(),bName);
		if(it == cityName.end()){
			cityName.push_back(bName);
			v = cityName.size()-1;
		} else{
			v = it - cityName.begin();
		}
		
		//cout << aName << ", " << bName << endl;
		
		s_t = strtok(NULL,",");
		edgeName.push_back(s_t);
		
		cps = strtok(NULL,",");
		sscanf(cps,"%d",&w);
		edgeWeight.push_back(w);
		
		// stroe the edge info to the edge list
		if(w<graph[u][v]){
			graph[u][v]=w;
			graph[v][u]=w;
			edgeNameTable[u][v] = i;
			edgeNameTable[v][u] = i;
		}
	}
	//	n = i; // the terminating i is the number of cities
	
	
	// for test only
	/*
	for(i=0;i<cityName.size();i++){
		cout << "#" << i << ": " << cityName[i] << endl;
	}*/
	
	
	// FloydWarshall's
	V = cityName.size();
	// initialize the graph
	for(i=0;i<V;i++) graph[i][i] = 0;
	// initialize the parent path array
	for(i=0;i<V;i++) for(j=0;j<V;j++) p[i][j] = i;
	
	for(int k=0;k<V;k++)
		for(i = 0;i<V;i++)
			for(j=0;j<V;j++)
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
					p[i][j] = p[k][j];
				}
	
	
	// deal with the query
	bool first = true;
	while(fgets(temp,10000,stdin)!=NULL){
		aName = strtok(temp,",");
		bName = strtok(NULL,",\n");
		it = find(cityName.begin(),cityName.end(),aName);
//		printf("%d\n",cityName.end()-cityName.begin());
		u = it - cityName.begin();
		it = find(cityName.begin(),cityName.end(),bName);
		v = it - cityName.begin();
		if(first)	first = false;
		else cout << endl << endl;
		query(u,v);
	}
	
	// for test only
	/*
	for(i=0;i<V;i++){
		for(j=0;j<V;j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}*/
	
	
	while(1);
	return 0;
}
