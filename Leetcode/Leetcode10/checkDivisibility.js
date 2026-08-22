/**
 * @param {number} n
 * @return {boolean}
 */
var checkDivisibility = function(n) {
    let sum = 0, product = 1;
    let n1 = n;
    while (n1 !== 0) {
        sum += n1 % 10;
        product *= n1 % 10;
        n1 = Math.trunc(n1 / 10);
    }
    return n % (sum + product) === 0;
};