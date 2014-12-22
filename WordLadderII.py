class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    def findLadders(self, start, end, dict):
        dict.insert(0, start)
        dict.append(end)
        
        return None
def main():
    start  = "hit"
    end    = "cog"
    dict = ["hot","dot","dog","lot","log"]
    s = Solution()
    print s.findLadders(start, end, dict)
main()