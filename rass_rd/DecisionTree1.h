#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree1 {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[1] <= 1.3399999737739563) {
                            if (x[2] <= -171.15499877929688) {
                                if (x[0] <= -142.87999725341797) {
                                    if (x[2] <= -171.34500122070312) {
                                        return -60;
                                    }

                                    else {
                                        return -21;
                                    }
                                }

                                else {
                                    if (x[3] <= 1.5699996948242188) {
                                        return 62;
                                    }

                                    else {
                                        return -43;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= -10.65499997138977) {
                                    if (x[3] <= 81.19499969482422) {
                                        return 8;
                                    }

                                    else {
                                        return -46;
                                    }
                                }

                                else {
                                    if (x[3] <= -142.0) {
                                        return -15;
                                    }

                                    else {
                                        if (x[1] <= -0.1549999713897705) {
                                            return -39;
                                        }

                                        else {
                                            return -67;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 152.0) {
                                if (x[3] <= 12.665000915527344) {
                                    if (x[3] <= -37.75) {
                                        return -11;
                                    }

                                    else {
                                        return 6;
                                    }
                                }

                                else {
                                    if (x[1] <= 15.145000398159027) {
                                        return -20;
                                    }

                                    else {
                                        if (x[5] <= -123.69499588012695) {
                                            return 9;
                                        }

                                        else {
                                            return -22;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= -177.0) {
                                    if (x[4] <= -76.5) {
                                        return -17;
                                    }

                                    else {
                                        if (x[2] <= -178.5) {
                                            return -3;
                                        }

                                        else {
                                            return -57;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 1.5) {
                                        return -9;
                                    }

                                    else {
                                        return -25;
                                    }
                                }
                            }
                        }
                    }

                protected:
                };
            }
        }
    }
