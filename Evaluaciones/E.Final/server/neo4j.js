let neo4j = require('neo4j-driver').v1;

module.exports = (function() {
  return {
    neo4j: neo4j,
    driver: neo4j.driver('bolt://neo4j', neo4j.auth.basic('neo4j', 'test'))
  };
})();
