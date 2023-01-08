class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int count = 0;
        unordered_map<string, int> um;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                // Consider each possible pair of points
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int m_num, m_den, c_num, c_den, f;
                m_den = c_den = x1 - x2;

                if(m_den == 0) { 
                    /*
                        if x1 - x2 == 0:
                            slope and intercept are INF
                        
                        - In this case we will not be able to identify parallel lines from concurrent ones by slope
                        - So we use the intercept as a measure to check concurrency of lines and use the x-coordinate here
                    */
                    m_num = INT_MAX;
                    c_num = x1;

                } else {

                    /*
                        - We calculate slope & intercept in form of fractions storing them as numerators and denominators
                            this avoids any error that may occur due to precision loss of float or double values
                        
                        - if val == 0:
                            we make numerator & denominator zero
                    */

                    /* slope
                        m = (y1 - y2)
                            ---------
                            (x1 - x2) 
                    */   
                    m_num = y1 - y2;
                    if(m_num == 0) m_den = 0;
                    else {
                        f = __gcd(abs(m_num), abs(m_den));
                        m_num /= f;
                        m_den /= f;
                        if((m_num < 0 and m_den < 0) or (m_num >=0 and m_den < 0)) {
                            m_num *= -1;
                            m_den *= -1;
                        }
                    }

                    /* intercept
                        c = y1 * (x1 - x2) - x1 * (y1 - y2)
                            -------------------------------
                                    (x1 - x2)
                    */
                    c_num = y1 * (x1 - x2) - x1 * (y1 - y2);
                    if(c_num == 0) c_den = 0;
                    else {
                        f = __gcd(abs(c_num), abs(c_den));
                        c_num /= f;
                        c_den /= f;
                        if((c_num < 0 and c_den < 0) or (c_num >=0 and c_den < 0)) {
                            c_num *= -1;
                            c_den *= -1;
                        }
                    }
                }

                // We hash each combination of slope + intercept in fractional forms to a string to check later
                string s = to_string(m_num) + to_string(m_den) + to_string(c_num) + to_string(c_den);
                um[s]++;
            }
        }

        for(auto it: um) count = max(count, it.second);

        /*
            count: is the total combination possible between all points on the same line
                                               p
            So if there are p points there are  C  combinations of 2 points forming the same line
                                                 2   
            Here, p is the answer
            Therefore,  p
                         C  =  count;
                          2
        */ 

        // p * (p - 1) = 2 * count
        // p = (1 + sqrt(1 + 8*count)) / 2

        return (1 + sqrt(1 + 8 * count)) / 2;
    }
};