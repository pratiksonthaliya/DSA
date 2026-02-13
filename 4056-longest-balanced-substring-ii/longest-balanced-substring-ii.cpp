#define ll long long
class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<ll,ll> ab, bc, ca, abc;
        ll cnta = 0, cntb = 0, cntc = 0;
        ll longestLength = 1;

        ab[0] = bc[0] = ca[0] = abc[0] = 0;

        char currentChar = s[0];
        ll len = 0;
        for(int i = 0; i < s.length(); i++){
            if(currentChar == s[i]) len++;
            else { len = 1; currentChar = s[i]; }
            longestLength = max(longestLength, len);
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') cnta++;
            else if(s[i] == 'b') cntb++;
            else cntc++;

            ll abId  = (ll)(cntb - cnta) << 32 | ((ll)cntc & 0xFFFFFFFFLL);
            ll bcId  = (ll)(cntb - cntc) << 32 | ((ll)cnta & 0xFFFFFFFFLL);
            ll caId  = (ll)(cntc - cnta) << 32 | ((ll)cntb & 0xFFFFFFFFLL);
            ll abcId = (ll)(cntb - cnta) << 32 | ((ll)(cntc - cnta) & 0xFFFFFFFFLL);

            if(!ab.count(abId)) ab[abId] = i + 1;
            else longestLength = max(longestLength, i - ab[abId] + 1);

            if(!bc.count(bcId)) bc[bcId] = i + 1;
            else longestLength = max(longestLength, i - bc[bcId] + 1);

            if(!ca.count(caId)) ca[caId] = i + 1;
            else longestLength = max(longestLength, i - ca[caId] + 1);

            if(!abc.count(abcId)) abc[abcId] = i + 1;
            else longestLength = max(longestLength, i - abc[abcId] + 1);
        }
        return longestLength;
    }
};