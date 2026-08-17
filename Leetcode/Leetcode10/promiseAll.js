/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const ans = new Array(functions.length);

        let idx = 0;
        functions.forEach((func, id) => {
            func().then(res => {
                ans[id] = res;
                idx++;
                if (idx == functions.length) resolve(ans);
            }).catch(e => reject(e));
        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */