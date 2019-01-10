//In an election, the i-th vote was cast for persons[i] at time times[i].

//Now, we would like to implement the following query function: TopVotedCandidate.q(int t)
//will return the number of the person that was leading the election at time t.  

//Votes cast at time t will count towards our query.  In the case of a tie, the most recent
//vote (among tied candidates) wins.


class TopVotedCandidate {
public:
    vector<int> wins;
    vector<int> voteTimes;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        voteTimes = times;
        
        map<int,int> votes;
        votes[persons[0]] = 1;
        int maxSoFar = persons[0];
        wins.push_back(persons[0]);
        
        
        for(int i = 1; i < persons.size(); i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= votes[maxSoFar])
                maxSoFar = persons[i];
            wins.push_back(maxSoFar);
        }
    }
    
    int q(int t) {
        int position = lower_bound(voteTimes.begin(),voteTimes.end(),t) - voteTimes.begin();
        if(position >= voteTimes.size()) position = voteTimes.size()-1;
        
        while(voteTimes[position] > t) position--;
        
        return wins[position];
    }
};