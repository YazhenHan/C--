/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const map1 = new Map();
    for (const element of arr1) {
        map1.set(element.id, element);
    }

    const map2 = new Map();
    for (const element of arr2) {
        map2.set(element.id, element);
    }

    const ans = [];
    for (const element of arr1) {
        if (map2.has(element.id)) {
            ans.push(Object.assign({}, element, map2.get(element.id)));
        } else {
            ans.push(element);
        }
    }

    for (const element of arr2) {
        if (!map1.has(element.id)) {
            ans.push(element);
        }
    }

    ans.sort((a, b) => a.id - b.id);
    return ans;
};