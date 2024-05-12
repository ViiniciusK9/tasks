

""" Instructor code """

def word_break(s, words, i=0):
    if i == len(s):
        return True
    else:
        for word in words:
            if word == s[i:i+len(word)] and word_break(s, words, i+len(word)):
                return True
        return False
 
 
def word_break(s, words):
    def rec(s, words, i=0):
        if i == len(s):
            return True
        else:
            for j in range(i+1, len(s)+1):
                if s[i:j] in words and rec(s, words, j):
                    return True
            return False
    words = set(words)
    return rec(s, words)
 
 
def word_break(s, words):
    def rec(s, words, i=0, lookup=None):
        lookup = {} if lookup is None else lookup
        if i in lookup:
            return lookup[i]
        if i == len(s):
            return True
        else:
            for j in range(i+1, len(s)+1):
                if s[i:j] in words and rec(s, words, j, lookup):
                    lookup[i] = True
                    return lookup[i]
            lookup[i] = False
            return lookup[i]
    words = set(words)
    return rec(s, words)
 
 
def word_break(s, words):
    k = len(s)
    words = set(words)
    dp = [False]*(k+1)
    dp[0] = True
    for i in range(1, k+1):
        for j in range(i):
            if s[j:i] in words and dp[j]:
                dp[i] = True
                break
    return dp[k]
 
 
class Trie:
    def __init__(self, is_end=False):
        self.children = {}
        self.is_end = is_end
 
    def insert(self, s):
        node = self
        for ch in s:
            if ch not in node.children:
                node.children[ch] = Trie()
            node = node.children[ch]
        node.is_end = True
 
 
def word_break(s, words):
    k = len(s)
    trie = Trie()
    for word in words:
        trie.insert(word)
    dp = [False]*(k+1)
    dp[0] = True
    for i in range(len(s)):
        node = trie
        for j in range(i, len(s)):
            if s[j] not in node.children:
                break
            node = node.children[s[j]]
            if node.is_end and dp[i]:
                dp[j+1] = True
    return dp[k]