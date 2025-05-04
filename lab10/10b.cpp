#include<iostream>
#include<map>
#include<vector>

using namespace std;
int main()
{
    int t;
    cout << "Enter the no of test cases:\n";
    cin >> t;

    while(t--)
    {
        int n;
        cout << "Enter the number of three letter string:\n";
        cin >> n;

        vector<vector<string>>words(3,vector<string>(n));
        map<string,int>wordcount;

        cout << "Enter the words:\n";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> words[i][j];
                wordcount[words[i][j]]++;
            }
        }
        vector<int>scores(3,0);

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {
                string word = words[i][j];
                if(wordcount[word]==1)
                {
                    scores[i]+=3;
                }
                else if(wordcount[word]==2)
                {
                    scores[i]+=1;
                }
            }
        }
        cout << "Their scores are:\n";
        cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
    }
    return 0;
}