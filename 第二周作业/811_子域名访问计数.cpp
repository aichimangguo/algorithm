class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) { 
      for(auto & strValue : cpdomains)
      {
        int nPos = strValue.find(" ");
        string strCount = strValue.substr(0, nPos);
        string strAddress = strValue.substr(nPos + 1, strValue.size());
        string strSubAddress = "";
        for(int i = strAddress.size() - 1; i >= 0; i--)
        {
            if(strAddress[i] != '.')
            {
                strSubAddress = strAddress[i] + strSubAddress;
            }
            else
            {
                m_strMap[strSubAddress] += atoi(strCount.c_str());
                strSubAddress = "." + strSubAddress;
            }
        }

        m_strMap[strAddress] += atoi(strCount.c_str());
      }

    vector<string> vecValue;
    for(auto& strValue : m_strMap)
    {
        string strvalue = to_string(strValue.second) + " ";
        strvalue += strValue.first;
        vecValue.push_back(strvalue);
    }          
    return vecValue;
      
    }

private:
 unordered_map<string, int>  m_strMap;    
};
