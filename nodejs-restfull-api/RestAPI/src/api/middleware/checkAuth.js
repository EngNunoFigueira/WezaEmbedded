const jwt = require('jsonwebtoken');
module.exports = (req, res, next) => {
    try {
        const token = req.body.token;
        const decoded = jwt.verify(token, process.env.JWT_KEY);
        next();
    } catch (error) {

        return res.status(404).json({
            message: "token verification failed: " + error
        });
    }
};