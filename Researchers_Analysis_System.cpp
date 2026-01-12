#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const int I = INT_MAX; 

struct Node{
    int id;
    string name;
    string institute;
    string email;
    int totalColaboration;

    Node(int d,string a, string b, string c){
        id=d;
        name = a;
        institute = b;
        email = c;
    }
};

struct Tree{
    Node *value;
    Tree* left = NULL;
    Tree* right = NULL;

    Tree* insert(Tree*& rt,Node* a){
        Tree* t = new Tree;
        t->value = a;

        if(rt==NULL){
            rt=t;
            // return rt;
            return rt;
        }

        if(a->id<(rt->value->id)){
            rt->left=insert(rt->left,a);
        }else if(a->id>(rt->value->id)){
            rt->right=insert(rt->right,a);
        }else{
            cout<<a->name<<" already exist in Tree.\n";
            return NULL;
        }
        return rt=balanceAsAVL(rt);
    }

    Tree* search(Tree* rt, int k){
        if(rt==NULL || rt->value->id==k){
            return rt;
        }
        if(k<rt->value->id){
            return search(rt->left,k);
        }else{
            return search(rt->right,k);
        }
    }

    Tree* inorderSucc(Tree* t){
        Tree* curr= t;
        while (curr->left!=NULL)
        {
            curr=curr->left;
        }
        return curr;
        
    }

    Tree* deleteNode(Tree* rt, int k){
        if(k<rt->value->id){
            rt->left=deleteNode(rt->left,k);
        }else if(k>rt->value->id){
            rt->right=deleteNode(rt->right,k);
        }else{
            if(rt->left==NULL){
                Tree* temp=rt->right;
                delete rt;
                return balanceAsAVL(temp);
                // return temp;
            }else if(rt->right==NULL){
                Tree* temp=rt->left;
                delete rt;
                return balanceAsAVL(temp);
                // return temp;
            }

            Tree* temp = inorderSucc(rt->right);
            rt->value=temp->value;
            rt->right=deleteNode(rt->right,temp->value->id);
        
        }
        return balanceAsAVL(rt);
    }
    

    void inOrder(Tree* n){
        if(n==NULL){
            return;
        }
        inOrder(n->left);
        cout<<"ID: "<<n->value->id+1<<", Name: "<<n->value->name<<", Institute: "<<n->value->institute<<", Email: "<<n->value->email<<", Total Colaborations: "<<n->value->totalColaboration<<" \n";
        inOrder(n->right);
    }

    void preOrder(Tree* n){
        if(n==NULL){
            return;
        }
        cout<<n->value<<" ";
        preOrder(n->left);
        preOrder(n->right);
    }

    void postOrder(Tree* n){
        if(n==NULL){
            return;
        }
        postOrder(n->left);
        postOrder(n->right);
        cout<<n->value<<" ";
    }
    int height(Tree* a){
        if(a==NULL){
            return 0;
        }
        int l= height(a->left);
        int r= height(a->right);
        if(l>r){
            return 1+l;
        }else{
            return 1+r;
        }
    }

    Tree* rotateRight(Tree* rt){
        Tree* temp = rt->left;
        Tree* temp1 = temp->right;

        temp->right = rt;
        rt->left = temp1;

        return temp;
    }

    Tree* rotateLeft(Tree* rt){
        Tree* temp = rt->right;
        Tree* temp1 = temp->left;

        temp->left = rt;
        rt->right = temp1;

        return temp;
    }


    Tree* balanceAsAVL(Tree* rt){
        if(rt==NULL){
            return rt;
        }
        int l= height(rt->left);
        int r= height(rt->right);
        if(l-r== -1 || l-r==1 || l-r==0){
            return rt;
        }

        if(l>r && rt->left->left!=NULL){
            return rt = rotateRight(rt);
        }else if(r>l && rt->right->right!=NULL){
            return rt = rotateLeft(rt);
        }else if(l>r && rt->left->right!=NULL){
            rt->left = rotateLeft(rt->left);
            return rt = rotateRight(rt);
        }else if(r>l && rt->right->left!=NULL){
            rt->right = rotateRight(rt->right);
            return rt = rotateLeft(rt);
        }
    }
    
};

Tree* readTree(){
    Tree* t = NULL;
    // Reading data from file
    ifstream fin("authors_info.csv");
    if (!fin.is_open()) {
        cerr << "Error: Could not open file 'authors_info.csv'" << endl;
    }

    string line;
    int lines = 0;
    while (getline(fin, line)) {
        vector<string> lineData;
        stringstream s(line);
        string word;
        // Split the line by comma
        while (getline(s, word, ',')) {
            lineData.push_back(word);
        }
        
        if(lines!=0){
            // stringstream bb(lineData[0]);
            // string nym;
            // bb>>nym;
            string nym = lineData[0];
            // stringstream cc(lineData[1]);
            string inst=lineData[1];
            // cc>>inst;
            // stringstream dd(lineData[2]);
            // string email;
            // dd>>email;
            string email = lineData[2];
            t->insert(t,(new Node(lines-1,nym,inst,email)));
        }
        lines++;
    }

    fin.close();

    return t;
}

struct AGraph{
    int **G;
    string *arr;
    int columnCount;
};



AGraph* readGraph(AGraph* a){
    int columnCount = 0;
    string *arr;
	int **G;
    ifstream fin("author_collaborations_with_data.csv");
    if (!fin.is_open()) {
        cerr << "Error: Could not open file 'ODI_data.csv'" << endl;
    }

    string line;
    int lines = 0;
    while (getline(fin, line)) {
        vector<string> lineData;
        stringstream s(line);
        string word;
        while (getline(s, word, ',')) {
            lineData.push_back(word);
            if(lines==0)
			columnCount++;
        }
        
	if(lines==0){

		arr = new string[columnCount-1];
		G=new int*[columnCount-1];
		for(int i=0;i<columnCount-1;i++){
			G[i]=new int[columnCount-1];
			stringstream abc(lineData[i+1]);
			string st;
			abc>>st;
			arr[i]=st;
		}
    }else{
		for(int i=0;i<columnCount-1;i++){
			stringstream bb(lineData[i+1]);
			int ind;
			bb>>ind;
			G[lines-1][i]=ind;
		}
    }
        
        lines++;
        
    }

    fin.close();
    a->columnCount=columnCount-1;
    a->arr=arr;
    a->G=G;
    return a;
}

AGraph* getDifficultyGraph(AGraph* a){
    AGraph* dg = new AGraph();
    dg->columnCount = a->columnCount;
    dg->arr=a->arr;
    dg->G = new int*[dg->columnCount];
    for (int i = 0; i < a->columnCount; i++)
    {
        dg->G[i] = new int[dg->columnCount];
        for (int j = 0; j < a->columnCount; j++)
        {
            if(a->G[i][j]!=0){
                dg->G[i][j] = (100/a->G[i][j]);
            }else{
                dg->G[i][j] = 0;
            }
        } 
    }
    return dg; 
}

void showResearcherDetail(Tree* t, AGraph* a, int target){
    Tree* n = t->search(t,target);
    if(n!=NULL){
        cout<<"ID: "<<n->value->id+1<<", Name: "<<n->value->name<<", Institute: "<<n->value->institute<<", Email: "<<n->value->email<<"\nTotal Colaborations: "<<n->value->totalColaboration<<" \nCollaboration Detail: \n";
        int cnt=0;
        for (int i = 0; i < a->columnCount; i++)
        {
            if(a->G[target][i]!=0){
                cnt++;
                cout<<a->arr[i]<<": "<<a->G[target][i]<<", ";
                if(cnt%5==0){
                    cout<<"\n";
                }
            }
        }
        cout<<"\n";
    }else{
        cout<<"TagetID: "<<target<<", not exist in record.\n";
    }
}
void updateNode(AGraph* c, Tree* b){
    for (int i = 0; i < c->columnCount; i++)
    {
        int total = 0;
        for (int j = 0; j < c->columnCount; j++)
        {
            if(c->G[i][j]!=0){
                total+=c->G[i][j];
            }
        }
        (b->search(b,i))->value->totalColaboration = total;
    }
}
struct Rec{
    int *visited;
    int *distance;
    int *parent;
    int v;
    int from;
    Rec(int a,int b){
        v=a;
        from=b;
        visited=new int[a];
        distance=new int[a];
        parent=new int[a];
        for (int i = 0; i < a; i++)
        {
            visited[i]=0;
            distance[i]=I;
            parent[i]=-1;
        }
        distance[b]=0;
        
    }
    bool isVisited(){
        for (int i = 0; i < v; i++)
        {
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
    void display(int s){
        if(distance[s]==I){
            cout<<"No path exist from "<<from<<" to "<<"s\n";
            return;
        }
        cout<<"("<<from<<", "<<s<<")"<<": "<<distance[s];
        int j=s;
        cout<<" Path: "<<j;
        while(j!=from){
            cout<<"<-"<<parent[j];
            j=parent[j];
        }
        cout<<endl; 
    }

    void display(){
        for (int i = 0; i < v; i++)
        {
            if(distance[i]==I){
              cout<<"No Link exist between "<<from<<" and "<<i<<"\n";
              continue;;
            }
            cout<<"("<<from<<", "<<i<<")"<<": "<<distance[i];
            int j=i;
            cout<<" Link: "<<j;
            while(j!=from){
                cout<<"<-"<<parent[j];
                j=parent[j];
            }
            cout<<endl;
        }
        
    }
};
Rec Dijestra(int **g, int V,int curr,Rec rec){
    rec.visited[curr]=1;
    int min = I;
    int k=-1;
    if(!rec.isVisited() || rec.isVisited()){
        for (int i = 0; i < V; i++)
        {
            if(g[curr][i]!=0 && !rec.visited[i] && rec.distance[i]>g[curr][i]+rec.distance[curr] ){
                rec.distance[i]=g[curr][i]+rec.distance[curr];
            }
            if(g[curr][i]!=0 && rec.distance[i]<min && !rec.visited[i]  && rec.distance[i]>=g[curr][i]+rec.distance[curr]){
                min=rec.distance[i];
                k=i;
            }
            if(g[curr][i]!=0 && rec.distance[i]>g[curr][i]+rec.distance[curr] ){
                rec.distance[i]=g[curr][i]+rec.distance[curr];
                // int p = rec.parent[i];
                rec.parent[i]=curr;
                rec = Dijestra(g,V,i,rec);
            }
        } 
        if(k!=-1){
            rec.parent[k]=curr;
            rec = Dijestra(g,V,k,rec);
        } 
        if(!rec.isVisited()){
          rec = Dijestra(g,V,rec.parent[curr],rec);
          rec = Dijestra(g,V,curr,rec);
        }
    }
    return rec;
    
}

void showResearcherLinks(AGraph* a, int target){
    cout<<"Links of "<<a->arr[target]<<" with other authors: \n";
    Rec rec = Rec(a->columnCount,target);
    rec = Dijestra(a->G,a->columnCount,target,rec);
    for (int i = 0; i < a->columnCount; i++)
    {
        if(target==i){
            continue;
        }
        if(rec.distance[i]==I){
            cout<<"No Link exist between "<<a->arr[target]<<" and "<<a->arr[i]<<"\n";
            continue;;
        }
        cout<<"("<<a->arr[target]<<", "<<a->arr[i]<<")"<<": "<<rec.distance[i];
        int j=i;
        cout<<" --> EasiestLink: "<<a->arr[j];
        while(j!=target){
            cout<<"<-"<<a->arr[rec.parent[j]];
            j=rec.parent[j];
        }
        cout<<endl;
    }
}

void getEasiestLink(AGraph* a, int source , int target){
    cout<<"EasiestLink of "<<a->arr[source]<<" with "<< a->arr[target]<<": \n";
    Rec rec = Rec(a->columnCount,source);
    rec = Dijestra(a->G,a->columnCount,source,rec);
    if(rec.distance[target]==I){
        cout<<"No Link exist between "<<a->arr[source]<<" and "<<a->arr[target]<<"\n";
    }else{
        cout<<"("<<a->arr[source]<<", "<<a->arr[target]<<")"<<": "<<rec.distance[target];
        int j=target;
        cout<<" --> EasiestLink: "<<a->arr[j];
        while(j!=source){
            cout<<"<-"<<a->arr[rec.parent[j]];
            j=rec.parent[j];
        }
    }
    cout<<endl;
}

struct Heap {
    Node** arry;
    int curr;
    int size;

    Heap() {
        size = 10;
        curr = -1; 
        arry = new Node*[size];
    }

    Heap(int a) {
        size = a;
        curr = -1;
        arry = new Node*[size];
    }

    void insert(Node* a) {
        if (curr == size - 1) {
            cout << "Heap is full." << endl;
        } else {
            arry[++curr] = a;     
            adjustInsertion(curr);  
        }
    }

    void adjustInsertion(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && arry[index]->totalColaboration > arry[parent]->totalColaboration) {
            swap(arry[index], arry[parent]);
            adjustInsertion(parent);  
        }
    }

    Node* deleteTop() {
        if (curr < 0) {
            cout << "Heap is empty.";
            return NULL;
        }
        Node* a = arry[0];
        arry[0] = arry[curr--];
        adjustDeletion(0);
        return a;
    }

    void adjustDeletion(int index) {
        int lc = (index * 2) + 1;  
        int rc = (index * 2) + 2;  
        int largest = index;

        if (lc <= curr && arry[lc]->totalColaboration > arry[largest]->totalColaboration) {
            largest = lc;
        }

        if (rc <= curr && arry[rc]->totalColaboration > arry[largest]->totalColaboration) {
            largest = rc;
        }

        if (largest != index) {
            swap(arry[index], arry[largest]);
            adjustDeletion(largest);
        }
    }

    void display() {
        for (int i = 0; i <= curr; i++) {
            cout << arry[i]->totalColaboration << " ";
        }
        cout << endl;
    }

    void preOrder(int index) {
        if (index > curr) {
            return;
        }
        int lec = (index * 2) + 1;  
        int ric = (index * 2) + 2;  
        cout << arry[index]->totalColaboration << ", ";
        preOrder(lec);
        preOrder(ric);
    }

    void inOrder(int index) {
        if (index > curr) {
            return;
        }
        int lec = (index * 2) + 1;  
        int ric = (index * 2) + 2;  
        inOrder(lec);
        cout << arry[index]->totalColaboration << ", ";
        inOrder(ric);
    }

    void postOrder(int index) {
        if (index > curr) {
            return;
        }
        int lec = (index * 2) + 1;  
        int ric = (index * 2) + 2; 
        postOrder(lec);
        postOrder(ric);
        cout << arry[index]->totalColaboration << ", ";
    }
};


void getPanel(Tree* g, AGraph* a){
    Heap* p = new Heap(a->columnCount);
    for (int i = 0; i < a->columnCount; i++)
    {
        p->insert(g->search(g,i)->value);
    }
    if(p->curr<4){
        cout<<"Researchers are less than 5 in record.\n";
        return;
    }
    cout<<"Top 5 Researchers are given below: \n";
    for (int i = 0; i < 5; i++)
    {
        Node* curr = p->deleteTop();
        cout<<"Rank: "<<i+1<<", ID: "<<curr->id+1<<", Name: "<<curr->name<<", Institute: "<<curr->institute<<", Email: "<<curr->email<<", Total Colaborations: "<<curr->totalColaboration<<" \n";
    }
}

int menu(){
    int a;
    cout<<"Press 1 to get Panel of Top 5 Researchers.\nPress 2 to get details of a Researcher.\nPress 3 to get All Easiest Links of a Researcher. \nPress 4 to get Easiest Link between Two Researchers.\nPress 5 to get all Researchers Detail.\nPress 0 to Exit.\nEnter Choice: ";
    cin>>a;
    while (a!=1 && a!=2 && a!=3 && a!=4 && a!=5 && a!=0)
    {
        cout<<"Invalid Input.\n";
        a=menu();
    }
    return a;
    
}

int main() {
    Tree* t = readTree();
    AGraph* org =new AGraph();
    org = readGraph(org);
    AGraph* dg  = getDifficultyGraph(org);
    updateNode(org,t);
    
    // t->inOrder(t);
    // showResearcherDetail(t,org,0);
    // showResearcherLinks(dg,2);
    // getEasiestLink(dg,2,0);
    // getPanel(t,org);

    int a = 0;
    int b,c;
    int cnt;
    do
    {
        a=menu();
        switch (a)
        {
        case 1:
            getPanel(t,org);
            break;
        case 2:
            for (int i = 0; i < org->columnCount; i++)
            {
                cout<<i+1<<": "<<org->arr[i]<<", ";
                if(i%10 == 0 && i!=0){
                    cout<<"\n";
                }
            }
            cout<<"\nEnter respective number of the Researcher: ";
            cin>>b;
            while(b<1 || b>org->columnCount){
                cout<<"Invalid Number.\nPlease Enter valid number: ";
                cin>>b;
            }
            showResearcherDetail(t,org,b-1);
            break;
        case 3:
            for (int i = 0; i < org->columnCount; i++)
            {
                cout<<i+1<<": "<<org->arr[i]<<", ";
                if(i%10 == 0 && i!=0){
                    cout<<"\n";
                }
            }
            cout<<"\nEnter respective number of the Researcher: ";
            cin>>b;
            while(b<1 || b>org->columnCount){
                cout<<"Invalid Number.\nPlease Enter valid number: ";
                cin>>b;
            }
            showResearcherLinks(dg,b-1);
            break;
        case 4:
            for (int i = 0; i < org->columnCount; i++)
            {
                cout<<i+1<<": "<<org->arr[i]<<", ";
                if(i%10 == 0 && i!=0){
                    cout<<"\n";
                }
            }
            cout<<"\nEnter respective number of first Researcher: ";
            cin>>b;
            while(b<1 || b>org->columnCount){
                cout<<"Invalid Number.\nPlease Enter valid number: ";
                cin>>b;
            }
            cout<<endl;
            for (int i = 0; i < org->columnCount; i++)
            {
                cout<<i+1<<": "<<org->arr[i]<<", ";
                if(i%10 == 0 && i!=0){
                    cout<<"\n";
                }
            }
            cout<<"\nEnter respective number of second Researcher: ";
            cin>>c;
            while(c<1 || c>org->columnCount){
                cout<<"Invalid Number.\nPlease Enter valid number: ";
                cin>>c;
            }
            if(c==b){
                cout<<"Self Link is not Valid Here.\n";
                break;
            }
            getEasiestLink(dg,b-1,c-1);
            break;
        case 5:
            t->inOrder(t);
            break;
        case 0:
            cout<<"Program Ending...!\n";
            break;
        default:
            break;
        }
    } while (a!=0);
    
    // for (int i = 0; i < org->columnCount; i++)
    // {
    //     for (int j = 0; j < org->columnCount; j++)
    //     {
    //         cout<<org->G[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"Next: \n";
    // for (int i = 0; i < dg->columnCount; i++)
    // {
    //     for (int j = 0; j < dg->columnCount; j++)
    //     {
    //         cout<<dg->G[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // // Reading data from file
    // ifstream fin("author_collaborations_with_data.csv");
    // if (!fin.is_open()) {
    //     cerr << "Error: Could not open file 'ODI_data.csv'" << endl;
    //     return 1;
    // }

    // string line;
    // int lines = 0;
    // while (getline(fin, line)) {
    //     vector<string> lineData;
    //     stringstream s(line);
    //     string word;
    //     // Split the line by comma
    //     while (getline(s, word, ',')) {
    //         lineData.push_back(word);
    //         if(lines==0)
	// 		columnCount++;
    //     }
        
	// if(lines==0){

	// 	arr = new string[columnCount-1];
	// 	G=new int*[columnCount-1];
	// 	for(int i=0;i<columnCount-1;i++){
	// 		G[i]=new int[columnCount-1];
	// 		stringstream abc(lineData[i+1]);
	// 		string st;
	// 		abc>>st;
	// 		arr[i]=st;
	// 	}
    // }else{
	// 	for(int i=0;i<columnCount-1;i++){
	// 		stringstream bb(lineData[i+1]);
	// 		int ind;
	// 		bb>>ind;
	// 		// if(ind==999)ind=I;
	// 		G[lines-1][i]=ind;
	// 	}
    // }
        
    //     lines++;
        
    // }

    // fin.close();
    // prim(G);
    
    
    

    return 0;
}

