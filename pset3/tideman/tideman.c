#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;
// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool disturb_graph_time_continuum(int winner, int loser)
{
    while (winner !=loser )
    {       
        bool b =  false;
        for (int i = 0; i < pair_count; i++)
        {
            if (locked[i][winner])
            {
                winner = i;
                b = true;
            }
        }
        if (!b)
        {
            return false;
        }
    }
    if (winner == loser)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    { 
            preferences[ranks[i]][ranks[i]] = 0;

    for (int j = i+1; j < candidate_count; j++)
    {
        preferences[ranks[i]][ranks[j]]+=1;
    }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

for (int i = 0; i < candidate_count; i++)
{
    for (int j = i+1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair p;
                p.winner = i;
                p.loser = j;
                pairs[pair_count++] = p;
            }
           else if (preferences[j][i] > preferences[i][j])
            {
                pair p;
                p.winner = j;
                p.loser = i;
                pairs[pair_count++] = p;
            }
            else if (preferences[j][i] == preferences[i][j])
            {
                true;
            }

        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int largest = 0;
    int a[pair_count];
    for (int i = 0; i < pair_count; i++)
    {   
        a[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }
    for (int i = 0; i < pair_count; i++)
    { 
        if (a[i] < a[i+1])
        {
            largest = a[i+1];
            a[i+1] = a[i];
            a[i] = largest;
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
            for (int j = 0; j < pair_count; j++)
            {
            if (a[i] == preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner])
            {
            pair temp1 = pairs[i];
            pairs[i] = pairs[j];
            pairs[j] = temp1;
            }
            }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    
    for (int i = 0; i < pair_count; i++)
    {
            if (!disturb_graph_time_continuum(pairs[i].winner, pairs[i].loser))
                {
                locked[pairs[i].winner][pairs[i].loser] = true;
                }
        
        }
    return;
    }
        


// Print the winner of the election
void print_winner(void)
{
    
    for (int i = 0; i < candidate_count; i++)
    {
        bool looper = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                looper = true;
                break;
            }

        }

        if (looper) continue;
        if(!looper) 
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

