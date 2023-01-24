// Knight Probability in Chessboard

class Solution {
public:
    
    double knightProbability(int N, int K, int r, int c){
        
        if(K==0) return 1.0;
        
        vector<vector<double>> parentBoard(N,vector<double>(N,0.0));
        
        vector<vector<double>> childBoard(N,vector<double>(N,0.0));
        
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        
        parentBoard[r][c] = 1.0;
        
        for(int i=0;i<K;i++)
        {
            for(int p=0;p<N;p++)
            {
                for(int q=0;q<N;q++)
                {
                    double moveProb = parentBoard[p][q]/8.0;
                    
                    for(int w=0;w<8;w++)
                    {
                        cx = p + rowoffset[w];
                        cy = q + coloffset[w];

                        if(cx>=0 && cx<N && cy>=0 && cy<N)
                            childBoard[cx][cy] += moveProb;
                    }                    
                }
            }
            
            parentBoard = childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(N,0.0));
        }
        

        
        double knightProb = 0.0;
        
        for(int p=0;p<N;p++)
            for(int q=0;q<N;q++)
                   knightProb+=parentBoard[p][q];

        return knightProb;
    }
};