/* jshint node: true */

/**
 * Benchmark various MAC address parsing methods.
 *
 */
(function () {
  'use strict';

  var utils = require('./utils'),
      addon = require('../src/js/utils').requireAddon();

  var benchmark = new utils.Benchmark();
  // var decoder = new addon.RadiotapDecoder();

  benchmark
    .addFn('object creation', function (done) {

      var buf = new Buffer('000020006708040054c6b82400000000220cdaa002000000400100003c142411b4007c013ce072e6612bcc03fadc202a719fe3d6', 'hex');
      var i = 10000;
      var frame, pdu, freq, types;

      while (i--) {
        frame = new addon.Frame(127, buf);
        pdu = frame.getPdu(3);
        freq = pdu.getChannel();
        freq = pdu.getChannel();
        freq = pdu.getChannel();
        types = frame.getPduTypes();
      }
      done();

    })
    .run(1e2, function (stats) {
      console.dir(stats);
    });

})();