/**
 * @param {Object|Array} obj1
 * @param {Object|Array} obj2
 * @return {Object|Array}
 */
function objDiff(obj1, obj2) {
    if ((obj1 === null || typeof obj1 !== "object") || (obj2 === null || typeof obj2 !== "object") || Array.isArray(obj1) && !Array.isArray(obj2) || !Array.isArray(obj1) && Array.isArray(obj2)) {
        return obj1 === obj2 ? {} : [ obj1, obj2 ];
    }

    const ans = {};
    for (const key in obj1) {
        if (obj2.hasOwnProperty(key)) {
            const temp = objDiff(obj1[key], obj2[key]);
            if (Array.isArray(temp) || Object.keys(temp).length !== 0) {
                ans[key] = temp;
            }
        }
    }
    return ans;
};