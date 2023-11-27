function countMaxPalindromes(s: string, queries: number[][], days: number): number[] {
    const MOD = 1e9 + 7;
    const freq = new Array(s.length + 1).fill(0).map(() => new Array(26).fill(0));  // 2D array to store frequency of each character in a range
    for (let i = 1; i <= s.length; i++) {
        const c = s.charCodeAt(i - 1) - 97;
        for (let j = 0; j < 26; j++) {
            freq[i][j] = freq[i - 1][j];    // copy previous row values to current row
        }
        freq[i][c]++;
    }

    function countOddChars(left: number, right: number): number {
        let oddCount = 0;
        for (let i = 0; i < 26; i++) {
            const count = freq[right][i] - freq[left - 1][i];
            if (count % 2 !== 0) {
                oddCount++;
            }
        }
        return oddCount;
    }

    function countPairs(left: number, right: number): number {
        let pairCount = 0;
        for (let i = 0; i < 26; i++) {
            const count = freq[right][i] - freq[left - 1][i];
            pairCount += Math.floor(count / 2);
        }
        return pairCount;
    }

    function factorial(n: number): number {
        let res = 1;
        for (let i = 2; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    function countMaxPalindromesInRange(left: number, right: number): number {
        const oddCount = countOddChars(left, right);
        const pairCount = countPairs(left, right);
        const maxPalindromes = factorial(pairCount);
        if (oddCount > 0) {
            return (maxPalindromes * oddCount) % MOD;
        } else {
            return maxPalindromes;
        }
    }

    const result: number[] = [];
    for (let i = 0; i < days; i++) {
        const query = queries[i];
        result.push(countMaxPalindromesInRange(query[0], query[1]));
    }
    return result;
}
