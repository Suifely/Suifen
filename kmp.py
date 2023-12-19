class Filtration:
    # 获取next数组
    def get_next(self, T):
        i = 0
        j = -1
        next_val = [-1] * len(T)+1
        while i < len(T):
            if j == -1 or T[i] == T[j]:
                i += 1
                j += 1
                # next_val[i] = j
                if i < len(T) and T[i] != T[j]:
                    next_val[i] = j
                else:
                    next_val[i] = next_val[j]
            else:
                j = next_val[j]
        return next_val

    # KMP算法
    def kmp(self, S, T):
        i = 0
        j = 0
        times = 0
        next = self.get_next(T)
        while i < len(S) and j < len(T):
            if j == -1 or S[i] == T[j]:
                i += 1
                j += 1
            else:
                j = next[j]
            if j == len(T):
                times += 1
                j = next[j]
            # else:
            #     return -1
        return times


# if __name__ == '__main__':
haystack = 'abaaba'
needle = 'aba'

s = Filtration()
print(s.kmp(haystack, needle))
