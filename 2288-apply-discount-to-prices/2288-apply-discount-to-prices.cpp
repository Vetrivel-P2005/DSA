class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string result = "";
        double factor = (100.0 - discount) / 100.0;

        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }

            if (word.length() > 1 && word[0] == '$') {
                bool isPrice = true;
                for (size_t i = 1; i < word.length(); ++i) {
                    if (!isdigit(word[i])) {
                        isPrice = false;
                        break;
                    }
                }

                if (isPrice) {
                    long long originalPrice = stoll(word.substr(1));
                    double discountedPrice = originalPrice * factor;

                    stringstream formatSs;
                    formatSs << fixed << setprecision(2) << discountedPrice;
                    result += "$" + formatSs.str();
                    continue;
                }
            }
            
            result += word;
        }

        return result;
    }
};