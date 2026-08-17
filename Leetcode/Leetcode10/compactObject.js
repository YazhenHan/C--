/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    const dfs = (obj) => {
        if (!obj) return false;
        if (typeof obj !== "object") return obj;

        if (Array.isArray(obj)) {
            const ans = [];
            for (const element of obj) {
                const temp = dfs(element);
                if (temp) ans.push(temp);
            }
            return ans;
        } else {
            const ans = {};
            for (const key in obj) {
                const temp = dfs(obj[key]);
                if (temp) ans[key] = temp;
            }
            return ans;
        }
    }

    return dfs(obj);
};