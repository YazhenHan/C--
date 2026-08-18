/**
 * @param {null|boolean|number|string|Array|Object} o1
 * @param {null|boolean|number|string|Array|Object} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if (o1 === o2) return true;
    if (o1 === null || o2 === null) return false;
    if (typeof o1 !== 'object' || typeof o2 !== 'object') return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;

    for (const key in o1) {
        if (!o2.hasOwnProperty(key) || !areDeeplyEqual(o1[key], o2[key])) {
            return false;
        }
    }

    for (const key in o2) {
        if (!o1.hasOwnProperty(key)) {
            return false;
        }
    }
    return true;
};