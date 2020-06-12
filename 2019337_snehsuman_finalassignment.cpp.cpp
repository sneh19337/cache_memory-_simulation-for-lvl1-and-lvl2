#include<iostream>
using namespace std;

//  main memory data initialization
void FetchingMain(int mainM[]){
	int n;
	int i=0;
	std::cout<<"***********************************************************************************************************"<<endl;
	std::cout<<"*********************************************************************************************************************************"<<endl;
	std::cout<<"\n\n\n\n\n\n\n\n\t\t\tBlocks"<<endl;
	std::cout<<"\n\nEnter  Block No."<<endl;
	std::cout<<"\n\nEnter the blocks which you want to see in cache "<<endl;
	std::cin>>n;
	while(  i < n)
	{
		int val,data;
		std::cin>>val>>data;
		mainM[val] = data;
	    i++;
	}
	std::cout<<"***********************************************************************************************************"<<endl;
	std::cout<<"*********************************************************************************************************************************"<<endl;
	std::cout<<"\n\n\n\t\t\tA Mock Representation Of Data in the block";
	std::cout<<"\n\nBlock     Data\n";
	i=0;
	while( i < 256)
	{
		if (mainM[i]!=0) {
			std::cout<<"   "<<i<<"         "<<mainM[i]<<endl;

		}
		i=i+1;;
	}
	std::cout<<"************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
}
void IniDeclaration(long long timedir,long long timeass,long long timesasso,long long timeD,long long timeAM,long long timeSM,int hit_Dir,int hit_Assoo,int hit_SetA,int miss_D,int miss_A, int miss_S,int dirMap[],int AsMap[],int Setamap[],int mainM[],int FeO[]){

	int i=0;
	// Initializing variable
	timeD = 0; //time for direct mapping
	timeAM = 0;//time for associative mapping
    timeSM = 0;//time for set associative mapping
	hit_Dir =0; //hit counters for D,A,S
	hit_Assoo = 0;
    hit_SetA = 0;
	miss_D = 0;//miss counters for D
	miss_A = 0;//miss counter for A
    miss_S = 0;//miss counter for S

	// Taking all the elements to be 0 as a sign of empty array
	while(  i < 128)
	{
		dirMap[i] = 0;
		AsMap[i] = 0;
        Setamap[i] = 0;
	    i++;
	}
	i=0;
	while(  i < 256)
	{
		mainM[i] = 0;
    	i++;
    }

}

long long calc5(long long timeass,long long TakenRC)
{

    long long jy=timeass+TakenRC;
    return jy;

}
int calc3(int set,int setl)
{
    int rew=set*setl;
    return rew;
}

// Cache structure after  every call
void ShowStructure(int noline,int dirMap[],int AsMap[],int Setamap[]){
    std::cout<<"************************************************************************************************************";
    std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\n\t\t\t\n\n\n\n\n\nCombined  Cache Structure for all the type of mappings "<<endl;
	std::cout<<"Line no.      Direct Mapping       Associative Mapping         Set Associative Mapping"<<endl;
	int i=0;
	while( i < noline)
	{
		std::cout<<"   "<<i<<"\t\t\t"<<dirMap[i]<<"\t\t\t\t"<<AsMap[i]<<"\t\t\t"<<Setamap[i]<<endl;
		i=i+1;;
	}


}

long long calc4(long long timedir ,int  TakenRC)
{
    long long ht=timedir + TakenRC;
    return ht;

}
int calc2(int number ,int setn)
{

    int red=number % setn;
    return red;
}
//  Direct Mapping
void DMapping(int number,int dirMap[],int TakenRC,long long timedir,int TakenRM,int hit_Dir,int mainM[],int miss_D,int noline){

    int y=calc2(number,noline);
	if (dirMap[y] == mainM[number]) {
		std::cout<<" Direct Mapping : "<<TakenRC<<endl;
		timedir = calc4(timedir , TakenRC);

		hit_Dir=hit_Dir+1;
	}
	else
	{
		dirMap[y] = mainM[number];
		std::cout<<" Direct Mapping : "<<TakenRM+TakenRC<<endl;
		std::cout<<"Miss occurred at= "<<mainM[number]<<endl;
		timedir = calc4(timedir , TakenRM);
		timedir =calc4(timedir, TakenRC);
		miss_D=miss_D+1;
	}
	std::cout<<"\t\t\tHit\t  ="<<hit_Dir<<endl;

}
//  Associative Mapping
void AMapping(int number,int noline,int miss_A,int hit_Assoo,int AsMap[],int mainM[],long long timeass,long long ComT,long long TakenRC,long long TakenRM){

	int i=0;
	while( i < noline)
	{
		if ( AsMap[i] == mainM[number]) {
			std::cout<<"\nAssociative Mapping : "<<calc5(((i+1)*ComT) , TakenRC)<<endl;
			timeass = calc5(timeass , ((i+1)*ComT));
			timeass=calc5(timeass,TakenRC);
			hit_Assoo=hit_Assoo+1;
			break;
		}
		i=i+1;
	}

	if ( i == noline ){
		int j=0;
		while(  j < noline)
		{
			if(AsMap[j] == 0 ){
				AsMap[j] = mainM[number];
				break;
			}
			j=j+1;;
		}
		if (j == noline){
			AsMap[0] = mainM[number];
		}
		std::cout<<"\n Associative Mapping :"<<(i)*ComT + TakenRC+ TakenRM<<endl;
		timeass = calc5(timeass , ((i+j)*ComT));
		timeass=calc5(timeass, TakenRC);
		timeass=calc5(timeass, TakenRM);
		std::cout<<"Miss occurred at = "<<mainM[number]<<endl;
		miss_A=miss_A+1;
	}
	std::cout<<"\t\t\tHit\t  ="<<hit_Assoo<<endl;
}

//  Set Associative Mapping
void SAMapping(int number,int setn,int setl,int Setamap[],int mainM[],int hit_SetA,long long timesasso,long long ComT,long long TakenRC,int miss_S,long long TakenRM){

	int set;

	set = calc2(number , setn);

	int i=calc3(set,setl);
	while( i < (calc3(set + 1,setl)))
	{
		if( Setamap[i] == mainM[number]){
			std::cout<<"\n n- Set Associative Mapping : "<< ((i-(calc3(set,setl)))*ComT) + TakenRC<<endl;
			timesasso = calc5(timesasso , ((i-(calc3(set,setl)))*ComT));
			timesasso=calc5(timesasso , TakenRC) ;
			hit_SetA=hit_SetA+1;
			break;
		}
		i=i+1;
	}
	if (i == calc3(set+1,setl)){
		int j=calc3(set,setl);
		while(  j < (calc3(set+1,setl)))
		{
			if(Setamap[j] == 0 ){
				Setamap[j] = mainM[number];
				break;
			}
			j=j+1;
		}
		if (j == (calc3(set + 1,setl))){
			Setamap[calc3(set,setl)] = mainM[number];
		}
		std::cout<<"\n n-Set Associative Mapping  : "<<((i-(calc3(set,setl)))*ComT) + TakenRC + TakenRM<<endl;
		timesasso = timesasso + ((i + j -(calc3(set,setl)))*ComT) + TakenRC + TakenRM;
		std::cout<<"Miss occurred at ="<<mainM[number]<<endl;
		miss_S=miss_S+1;
	}
	std::cout<<"\t\t\tHit\t   ="<<hit_SetA<<endl;
}

int calc(int noline , int setn)
{
    int res=noline / setn;
    return res;
}
 void Level1Inputs(int Level1M[]){
        int n;
        int i=0;
        std::cout<<"***********************************************************************************************************"<<endl;
        std::cout<<"*********************************************************************************************************************************"<<endl;
        std::cout<<"\n\n\n\n\n\n\n\n\t\t\tBlocks"<<endl;
        std::cout<<"\n\nEnter  Block No."<<endl;
        std::cout<<"\n\nEnter the blocks which you want to see in cache "<<endl;
        std::cin>>n;
        while(  i < n)
        {
            int val,data;
            std::cin>>val>>data;
            Level1M[val] = data;
            i++;
        }
        std::cout<<"***********************************************************************************************************"<<endl;
        std::cout<<"*********************************************************************************************************************************"<<endl;
        std::cout<<"\n\n\n\t\t\tA Mock Representation Of Data in the block in level 1 cache memory";
        std::cout<<"\n\nBlock     Data\n";
        i=0;
        while( i < 128)
        {
            if (Level1M[i]!=0) {
                std::cout<<"   "<<i<<"         "<<Level1M[i]<<endl;

            }
            i=i+1;;
        }
        std::cout<<"************************************************************************************************************";
        std::cout<<"*********************************************************************************************************************************";
    }
     void Level1Decl(long lvl2drc,long lvl2timeas,long lvl2assom,long lvl2timed,long lvl2timeam,long lvl2timesm,int lvl2hitDmap,int lvl2hit_asso,int lvl2hit_setA,int lvl2missDmap,int lvl2miss_A, int lvl2miss_S,int lvl2dirm[],int lvl2asmap[],int lvl2setm[],int Level1M[],int lvl2Feo[]){

        int i=0;
        // Initializing variable
        lvl2timed = 0; //time for direct mapping
        lvl2timeam = 0;//time for associative mapping
        lvl2timesm = 0;//time for set associative mapping
        lvl2hitDmap =0; //hit counters for D,A,S
        lvl2hit_asso = 0;
        lvl2hit_setA = 0;
        lvl2missDmap = 0;//miss counters for D
        lvl2miss_A = 0;//miss counter for A
        lvl2miss_S = 0;//miss counter for S

        // Taking all the elements to be 0 as a sign of empty array
        while(  i < 128)
        {
            lvl2dirm[i] = 0;
            lvl2asmap[i] = 0;
            lvl2setm[i] = 0;
            i++;
        }
        i=0;
        while(  i < 256)
        {
            Level1M[i] = 0;
            i++;
        }

    }

    long evaluate5(long lvl2timeas,long lvl2Takenrc)
    {

        long jy=lvl2timeas+lvl2Takenrc;
        return jy;

    }
    int evaluate3(int set,int lvl2setl)
    {
        int rew=set*lvl2setl;
        return rew;
    }

    // Cache structure after  every call
    void Level2_print(int lvl2noline,int lvl2dirm[],int lvl2asmap[],int lvl2setm[]){
        std::cout<<"************************************************************************************************************";
        std::cout<<"*********************************************************************************************************************************";
        std::cout<<"\n\n\t\t\t\n\n\n\n\n\nCombined  Cache Structure for all the type of mappings in level2 without the interference of main memory"<<endl;
        std::cout<<"Line no.      Direct Mapping       Associative Mapping         Set Associative Mapping"<<endl;
        int i=0;
        while( i < lvl2noline)
        {
            std::cout<<"   "<<i<<"\t\t\t"<<lvl2dirm[i]<<"\t\t\t\t"<<lvl2asmap[i]<<"\t\t\t"<<lvl2setm[i]<<endl;
            i=i+1;;
        }


    }

    long evaluate4(long lvl2drc ,int  lvl2Takenrc)
    {
        long ht=lvl2drc + lvl2Takenrc;
        return ht;

    }
    int evaluate2(int number ,int lvl2setn)
    {

        int red=number % lvl2setn;
        return red;
    }
    //  Direct Mapping
    void lvl2_dir(int number,int lvl2dirm[],int lvl2Takenrc,long lvl2drc,int lvl2rm,int lvl2hitDmap,int Level1M[],int lvl2missDmap,int lvl2noline){

        int y=evaluate2(number,lvl2noline);
        if (lvl2dirm[y] == Level1M[number]) {
            std::cout<<" Direct Mapping : "<<lvl2Takenrc<<endl;
            lvl2drc = evaluate4(lvl2drc , lvl2Takenrc);

            lvl2hitDmap=lvl2hitDmap+1;
        }
        else
        {
            lvl2dirm[y] = Level1M[number];
            std::cout<<" Direct Mapping : "<<lvl2rm+lvl2Takenrc<<endl;
            std::cout<<"Miss occurred at= "<<Level1M[number]<<endl;
            lvl2drc = evaluate4(lvl2drc , lvl2rm);
            lvl2drc =evaluate4(lvl2drc, lvl2Takenrc);
            lvl2missDmap=lvl2missDmap+1;
        }
        std::cout<<"\t\t\tHit\t  ="<<lvl2hitDmap<<endl;

    }
    //  Associative Mapping
    void lvl2_ass(int number,int lvl2noline,int lvl2miss_A,int lvl2hit_asso,int lvl2asmap[],int Level1M[],long lvl2timeas,long lvl2comT,long lvl2Takenrc,long lvl2rm){

        int i=0;
        while( i < lvl2noline)
        {
            if ( lvl2asmap[i] == Level1M[number]) {
                std::cout<<"\nAssociative Mapping : "<<evaluate5(((i+1)*lvl2comT) , lvl2Takenrc)<<endl;
                lvl2timeas = evaluate5(lvl2timeas , ((i+1)*lvl2comT));
                lvl2timeas=evaluate5(lvl2timeas,lvl2Takenrc);
                lvl2hit_asso=lvl2hit_asso+1;
                break;
            }
            i=i+1;
        }

        if ( i == lvl2noline ){
            int j=0;
            while(  j < lvl2noline)
            {
                if(lvl2asmap[j] == 0 ){
                    lvl2asmap[j] = Level1M[number];
                    break;
                }
                j=j+1;;
            }
            if (j == lvl2noline){
                lvl2asmap[0] = Level1M[number];
            }
            std::cout<<"\n Associative Mapping :"<<(i)*lvl2comT + lvl2Takenrc+ lvl2rm<<endl;
            lvl2timeas = evaluate5(lvl2timeas , ((i+j)*lvl2comT));
            lvl2timeas=evaluate5(lvl2timeas, lvl2Takenrc);
            lvl2timeas=evaluate5(lvl2timeas, lvl2rm);
            std::cout<<"Miss occurred at = "<<Level1M[number]<<endl;
            lvl2miss_A=lvl2miss_A+1;
        }
        std::cout<<"\t\t\tHit\t  ="<<lvl2hit_asso<<endl;
    }

    //  Set Associative Mapping
    void SAlvl2_ass(int number,int lvl2setn,int lvl2setl,int lvl2setm[],int Level1M[],int lvl2hit_setA,long lvl2assom,long lvl2comT,long lvl2Takenrc,int lvl2miss_S,long lvl2rm){

        int set;

        set = evaluate2(number , lvl2setn);

        int i=evaluate3(set,lvl2setl);
        while( i < (evaluate3(set + 1,lvl2setl)))
        {
            if( lvl2setm[i] == Level1M[number]){
                std::cout<<"\n n- Set Associative Mapping : "<< ((i-(evaluate3(set,lvl2setl)))*lvl2comT) + lvl2Takenrc<<endl;
                lvl2assom = evaluate5(lvl2assom , ((i-(evaluate3(set,lvl2setl)))*lvl2comT));
                lvl2assom=evaluate5(lvl2assom , lvl2Takenrc) ;
                lvl2hit_setA=lvl2hit_setA+1;
                break;
            }
            i=i+1;
        }
        if (i == evaluate3(set+1,lvl2setl)){
            int j=evaluate3(set,lvl2setl);
            while(  j < (evaluate3(set+1,lvl2setl)))
            {
                if(lvl2setm[j] == 0 ){
                    lvl2setm[j] = Level1M[number];
                    break;
                }
                j=j+1;
            }
            if (j == (evaluate3(set + 1,lvl2setl))){
                lvl2setm[evaluate3(set,lvl2setl)] = Level1M[number];
            }
            std::cout<<"\n n-Set Associative Mapping  : "<<((i-(evaluate3(set,lvl2setl)))*lvl2comT) + lvl2Takenrc + lvl2rm<<endl;
            lvl2assom = lvl2assom + ((i + j -(evaluate3(set,lvl2setl)))*lvl2comT) + lvl2Takenrc + lvl2rm;
            std::cout<<"Miss occurred at ="<<Level1M[number]<<endl;
            lvl2miss_S=lvl2miss_S+1;
        }
        std::cout<<"\t\t\tHit\t   ="<<lvl2hit_setA<<endl;
    }

    int evaluate(int lvl2noline , int lvl2setn)
    {
        int res=lvl2noline / lvl2setn;
        return res;
    }
        int lvl2dirm[128],lvl2asmap[128],lvl2setm[128],Level1M[256],lvl2Feo[128];//lvl2Feo is the order in which fetching will take place
        long lvl2Takenrc,lvl2rm,lvl2comT;
        int lvl2noline,lvl2setn,lvl2setl,lvl2fetchmemory;


        long lvl2drc,lvl2timeas,lvl2assom;
        long lvl2timed,lvl2timeam,lvl2timesm;
        int lvl2hitDmap,lvl2hit_asso,lvl2hit_setA;
        int lvl2missDmap,lvl2miss_A,lvl2miss_S;


        int dirMap[128],AsMap[128],Setamap[128],mainM[256],FeO[128];//FeO is the order in which fetching will take place
        long long TakenRC,TakenRM,ComT;
        int noline,setn,setl,fetchMemory;


        long long timedir,timeass,timesasso;
        long long timeD,timeAM,timeSM;
        int hit_Dir,hit_Assoo,hit_SetA;
        int miss_D,miss_A,miss_S;


int main (){
    int choice=0;
    std::cout<<"\t\t\t\t\t\t############################Computer Organization Final Assignment Project###################################################### ";
    std::cout<<"\t\t\t\t\t\t###############################NAME-SNEH SUMAN || ROLL NO-2019337###############################################################";
    std::cout<<"\n\n\n\n\n\n\n\n\nEnter the choice to enter in program-1(cache memory mapping) or program-2(level -2 cache memory)";
    std::cout<<"\n\n\n\n\n\n\n\n\nEnter your choice (1,2)"<<endl;
    std::cin>>choice;
    switch(choice){
    case 1:
    {


    std::cout<<"*********************************************************************************************************************************";
    std::cout<<"*********************************************************************************************************************************";

	std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\nThis is a demo program for showing and comparing the different mapping techniques of cache memory ";
	std::cout<<"\n\nEnter Cache Lines :"<<endl;//no of lines you want in the cache
	std::cin>>noline;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nInput the no of data to be read  from Cache: "<<endl;    // to take input
	std::cin>>TakenRC;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nThe data you want from main memory: "<<endl;//to take input from main memory
	std::cin>>TakenRM;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nThe data you want to check from cache : "<<endl;//comparison
	std::cin>>ComT;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nEnter the no. of Sets(out of -2,4,8,16,32,64) in Set Associative Mapping: "<<endl;
	std::cin>>setn;
	setl = calc(noline ,setn);
    std::cout<<"\n\n\nthe number of sets in set associative   ="<<setl<<endl;
    std::cout<<"\n\n the offset is in bits    ="<<7<<endl;
    std::cout<<"\n\n the tag is in bits      ="<<9<<endl;//32-16-7
	IniDeclaration( timedir, timeass, timesasso, timeD, timeAM, timeSM, hit_Dir, hit_Assoo, hit_SetA, miss_D, miss_A,  miss_S, dirMap,AsMap,Setamap,mainM,FeO);

	FetchingMain(mainM);

	std::cout<<"\n\nHow many checks  you want to be made by the system: ";
    std::cin>>fetchMemory;
    std::cout<<"\n\nData Replacement (MRU ) will take place if you try to add data to the same block.Hence what you will see will be the lastly entered data in the block ";
    std::cout<<"\n\n Specify Block numbers to get the cache structure at every step of WRITE/READ in cache\n";

    int i=0;
	while( i < fetchMemory)
	{
		std::cin>>FeO[i];
		i=i+1;
	}
	i=0;
	while( i < fetchMemory)
	{
		int number = FeO[i];
		std::cout<<"*********************************************************************************************************************************";
		std::cout<<"*********************************************************************************************************************************";
        std::cout<<"\n\n\n\nFrom the data    "<<"  "<< number<<"  "<<"mapped to       "<< "  "<<mainM[number]<<"\n";
        // direct mapping is done here
		DMapping(number,dirMap,TakenRC,timedir,TakenRM, hit_Dir,mainM, miss_D,noline);
        //associative mapping is done here
        AMapping(number, noline,miss_A,hit_Assoo,AsMap,mainM,timeass,ComT,TakenRC,TakenRM);
        //set associative mapping is done here
        SAMapping(number,setn,setl,Setamap,mainM,hit_SetA,timesasso,ComT,TakenRC,miss_S,TakenRM);
        //the cache structure after every memory call is shown through this function
		ShowStructure(noline, dirMap, AsMap, Setamap);
		i=i+1;
	}
        std::cout<<"*********************************************************************************************************************************";
        std::cout<<"*********************************************************************************************************************************";
    break;
    }
    case 2:
     {

        std::cout<<"The program here will be implementing the bonus assignment of implementing level 2 cache memory without the intervention of main memory"<<endl;
        std::cout<<"*********************************************************************************************************************************";
    std::cout<<"*********************************************************************************************************************************";
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\nThis is a demo program for showing and comparing the different mapping techniques of cache memory in level2 cache without main memory ";
	std::cout<<"\n\nEnter Cache Lines in level 2 cache memory :"<<endl;//no of lines you want in the cache
	std::cin>>lvl2noline;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nInput the no of data to be read  from lvl2 Cache: "<<endl;    // to take input
	std::cin>>lvl2Takenrc;
	std::cin>>lvl2rm;
	std::cin>>lvl2comT;
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"*********************************************************************************************************************************";
	std::cout<<"\n\nEnter the no. of Sets(out of -2,4,8,16,32,64) in Set Associative Mapping: "<<endl;
	std::cin>>lvl2setn;
	lvl2setl = evaluate(lvl2noline ,lvl2setn);
    std::cout<<"\n\n\nthe number of sets in set associative   ="<<lvl2setl<<endl;
    std::cout<<"\n\n the offset is in bits    ="<<8<<endl;
    std::cout<<"\n\n the tag is in bits      ="<<8<<endl;//32-16-8

	Level1Decl( lvl2drc, lvl2timeas, lvl2assom, lvl2timed, lvl2timeam, lvl2timesm, lvl2hitDmap, lvl2hit_asso, lvl2hit_setA, lvl2missDmap, lvl2miss_A,  lvl2miss_S, lvl2dirm,lvl2asmap,lvl2setm,Level1M,lvl2Feo);

	Level1Inputs(Level1M);

	std::cout<<"\n\nHow many checks  you want to be made by the system: ";
    std::cin>>lvl2fetchmemory;
    std::cout<<"\n\nData Replacement (MRU ) will take place if you try to add data to the same block.Hence what you will see will be the lastly entered data in the block ";
    std::cout<<"\n\n Specify Block numbers to get the cache structure at every step of WRITE/READ in cache\n";

    int i=0;
	while( i < lvl2fetchmemory)
	{
		std::cin>>lvl2Feo[i];
		i=i+1;
	}
	i=0;
	while( i < lvl2fetchmemory)
	{
		int number = lvl2Feo[i];
		std::cout<<"*********************************************************************************************************************************";
		std::cout<<"*********************************************************************************************************************************";
        std::cout<<"\n\n\n\nFrom the data    "<<"  "<< number<<"  "<<"mapped to       "<< "  "<<Level1M[number]<<"\n";
        // direct mapping is done here
		lvl2_dir(number,lvl2dirm,lvl2Takenrc,lvl2drc,lvl2rm, lvl2hitDmap,Level1M, lvl2missDmap,lvl2noline);
        //associative mapping is done here
        lvl2_ass(number, lvl2noline,lvl2miss_A,lvl2hit_asso,lvl2asmap,Level1M,lvl2timeas,lvl2comT,lvl2Takenrc,lvl2rm);
        //set associative mapping is done here
        SAlvl2_ass(number,lvl2setn,lvl2setl,lvl2setm,Level1M,lvl2hit_setA,lvl2assom,lvl2comT,lvl2Takenrc,lvl2miss_S,lvl2rm);
        //the cache structure after every memory call is shown through this function
		Level2_print(lvl2noline, lvl2dirm, lvl2asmap, lvl2setm);
		i=i+1;
	}
        std::cout<<"*********************************************************************************************************************************";
        std::cout<<"*********************************************************************************************************************************";

    break;
     }
    default:
        {std::cout<<"You are out of both the program choices";
        break;}

}return 0;
}












