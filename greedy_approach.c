#include <stdio.h>


float airport[11][11] =
{0,35,34,36,34,35,8,29,70,36,34,
35,0,2.6,11,22,6.4,30,6.8,36,36,13,
34,2.6,0,8.7,19,3,28,5.3,38,12,13,
36,11,8.7,0,14,6.9,31,8.7,46,4.5,18,
34,22,19,14,0,19,29,16,56,12,24,
35,6.4,3,6.9,19,0,24,6.1,41,9.1,14,
8,30,28,31,29,24,0,24,65,32,28,
29,6.8,5.3,8.7,16,6.1,24,0,41,9.9,10,
70,36,38,46,56,41,65,41,0,48,46,
36,36,12,4.5,12,9.1,32,9.9,48,0,19,
34,13,13,18,24,14,28,10,46,19,0};

float isbt[11][11] =
{0,9.1,7.2,14,23,9.5,26,6.3,42,15,4.8,
9.1,0,2.6,11,22,6.4,30,6.8,36,36,13,
7.2,2.6,0,8.7,19,3,28,5.3,38,12,13,
14,11,8.7,0,14,6.9,31,8.7,46,4.5,18,
23,22,19,14,0,19,29,16,56,12,24,
9.5,6.4,3,6.9,19,0,24,6.1,41,9.1,14,
26,30,28,31,29,24,0,24,65,32,28,
6.3,6.8,5.3,8.7,16,6.1,24,0,41,9.9,10,
42,36,38,46,56,41,65,41,0,48,46,
15,36,12,4.5,12,9.1,32,9.9,48,0,19,
4.8,13,13,18,24,14,28,10,46,19,0};

float railway_station[11][11] =
{0,5.8,5,9.7,16,7.2,23,2,41,11,9.1,
5.8,0,2.6,11,22,6.4,30,6.8,36,36,13,
5,2.6,0,8.7,19,3,28,5.3,38,12,13,
9.7,11,8.7,0,14,6.9,31,8.7,46,4.5,18,
16,22,19,14,0,19,29,16,56,12,24,
7.2,6.4,3,6.9,19,0,24,6.1,41,9.1,14,
23,30,28,31,29,24,0,24,65,32,28,
2,6.8,5.3,8.7,16,6.1,24,0,41,9.9,10,
41,36,38,46,56,41,65,41,0,48,46,
11,36,12,4.5,12,9.1,32,9.9,48,0,19,
9.1,13,13,18,24,14,28,10,46,19,0};

char* locations_index[] = {"", "IMA", "FRI", "ROBBER'S CAVE", "SAHASTRADHARA", "TAPKESHWAR TEMPLE", "LACHIVALA", "PALTAN BAZAAR", "ASSAN BARRAGE", "DEER PARK/ZOO", "BUDDHA TEMPLE"};

int num_loc;
int locations[11];
char start_pt;
float matloc[11][11];
int vis[] = {99,99,99,99,99,99,99,99,99,99,99};
float cost = 0;


void welcome()
{
    printf("\nWelcome Traveller!!\n\n\n");
    printf("This is the DOON TOUR OPTIMIZER.\n\n\n");

}


void print_start()
{
    if(start_pt== 'a')
    {

		printf("%s", "DEHRADUN RAILWAY STATION");
    }

    if(start_pt== 'b')
    {
        printf("%s", "DEHRADUN ISBT");
    }

    if(start_pt== 'c')
    {
        printf("%s", "JOLLY GRANT AIRPORT");
    }
}


void starting_point()
{
    printf("Depending on what mode of transport you used to reach Dehradun, \nplease tell us what will be the starting point for your journey?\n\na. Dehradun Railway Station\nb. Dehradun ISBT\nc. Jolly Grant Airport\n\nPlease enter 'a', 'b' or 'c' \n\n");
    scanf("%c",&start_pt);
    switch (start_pt)
    {
        case 'a': locations[0] = 11;
        printf("You chose: Dehradun Railway Station\n\n");
            break;
        case 'b': locations[0] = 12;
        printf("You chose: Dehradun ISBT\n\n");
            break;
        case 'c': locations[0] = 13;
        printf("You chose: Jolly Grant Airport\n\n");
            break;
        default: printf("Enter a valid choice PLEASE!!!!\n\n");
    }
}


void menu_and_input()
{
    int i;
    printf("Now,\n");
    printf("The places you could visit during your stay in Dehradun are-\n\n");
    printf("1. IMA\n2. FRI\n3. ROBBER'S CAVE\n4. SAHASTRADHARA\n5. TAPKESHWAR TEMPLE\n6. LACHIVALA\n7. PALTAN BAZAAR\n8. ASSAN BARRAGE\n9. DEER PARK/ZOO\n10.BUDDHA TEMPLE");
    printf("\n\nHow many locations do you want to visit from the above list?\n");
    scanf("%d",&num_loc);
    printf("\nEnter the locations..for instance if u want to visit FRI, enter '2'\n");
    for (i=1; i<=num_loc; i++)
    {
        scanf("%d",&locations[i]);
    }
}


void selected_locations()
{
	int i,j;
	if(locations[0]==11)
	{
		locations[0]=0;
		for(i=0;i<=num_loc;i++)
    	{
        	for(j=0;j<=num_loc;j++)
        	{
        		matloc[i][j]=railway_station[locations[i]][locations[j]];
			}
    	}

	}

	else if(locations[0]==12)
	{
		locations[0]=0;
		for(i=0;i<=num_loc;i++)
    	{
        	for(j=0;j<=num_loc;j++)
        	{
        		matloc[i][j]=isbt[locations[i]][locations[j]];
			}
    	}
	}

	else if(locations[0]==13)
	{
		locations[0]=0;
		for(i=0;i<=num_loc;i++)
    	{
        	for(j=0;j<=num_loc;j++)
        	{
        		matloc[i][j]=airport[locations[i]][locations[j]];
			}
    	}
	}
}


int check(int i)
{
	int j,flag = 0;
	for(j=0;j<num_loc+1;j++)
	{
		if(i==vis[j])
		{
			flag = 1;
		}
	}
	return flag;
}


int minimum(int a)
{
	int i,temp;
	float min = 999;
	for(i = 0;i<num_loc+1;i++)
	{
		if(locations[i]==a)
		{
			continue;
		}
		else if(check(locations[i]))
		{
			continue;
		}
		else
		{
			if(matloc[a][i]<min)
			{
				min = matloc[a][i];
				temp = locations[i];
			}
		}
	}
	cost = cost + min;
	return temp;
}


void display_path()
{
	int i;
	for(i=0;i<num_loc+1;i++)
	{
		printf("%s ---> ",locations_index[vis[i]]);
	}

}


void shortest_path()
{
	int i;
	vis[0] = 0;
	for(i=0;i<num_loc+1;i++)
	{
		if((i+1) == num_loc+1)
		{
			cost = cost + matloc[vis[i]][vis[0]];
		}
		else
		{
			vis[i+1] = minimum(vis[i]);
		}
	}
	display_path();
}


void entered_locations()
{
    printf("\nThe locations entered by you are -\n");
    int i;
    for(i=1;i<=num_loc;i++)
    {
        printf("%d\n",locations[i]);
    }
    printf("\n");
}


int main()
{
    welcome();

    starting_point();

    menu_and_input();

    entered_locations();

    selected_locations();

    printf("The most optimal route for you would be:\n");
    print_start();

    shortest_path();

    print_start();
    printf("\n");

    return 0;

}
