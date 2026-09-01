class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int litter_count = 0;
        
        int litter_idx[20][20];
        memset(litter_idx, -1, sizeof(litter_idx));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_idx[i][j] = litter_count++;
                }
            }
        }
        
        int target_mask = (1 << litter_count) - 1;
        
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1)));
        
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, mask, cur_energy, moves] = q.front();
            q.pop();
            
            if (mask == target_mask) {
                return moves;
            }
            
            if (cur_energy == 0) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int next_energy = cur_energy - 1;
                int next_mask = mask;
                
                if (classroom[nr][nc] == 'L' && litter_idx[nr][nc] != -1) {
                    next_mask |= (1 << litter_idx[nr][nc]);
                }
                
                if (classroom[nr][nc] == 'R') {
                    next_energy = energy;
                }
                
                if (next_energy > max_energy[nr][nc][next_mask]) {
                    max_energy[nr][nc][next_mask] = next_energy;
                    q.push({nr, nc, next_mask, next_energy, moves + 1});
                }
            }
        }
        
        return -1;
    }
};