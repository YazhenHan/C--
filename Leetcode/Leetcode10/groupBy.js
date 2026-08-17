/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const obj = new Object();
    for (const element of this) {
        const key = fn(element);
        if (obj.hasOwnProperty(key)) {
            obj[key].push(element);
        } else {
            obj[key] = [element];
        }
    }
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */