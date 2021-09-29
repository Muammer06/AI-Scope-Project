#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree2 {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[0] <= 147.0) {
                            if (x[0] <= -145.68499755859375) {
                                if (x[0] <= -157.5250015258789) {
                                    if (x[2] <= -175.9199981689453) {
                                        return 16;
                                    }

                                    else {
                                        return 35;
                                    }
                                }

                                else {
                                    if (x[3] <= 26.96500015258789) {
                                        return 16;
                                    }

                                    else {
                                        if (x[1] <= 1.1949999928474426) {
                                            return 72;
                                        }

                                        else {
                                            return 49;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= -122.06499862670898) {
                                    if (x[3] <= -18.549999952316284) {
                                        return 16;
                                    }

                                    else {
                                        if (x[1] <= -0.9049999713897705) {
                                            return 17;
                                        }

                                        else {
                                            return 5;
                                        }
                                    }
                                }

                                else {
                                    if (x[3] <= -106.5) {
                                        return 12;
                                    }

                                    else {
                                        return 65;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[3] <= -86.5) {
                                if (x[0] <= 158.5) {
                                    return 10;
                                }

                                else {
                                    return 31;
                                }
                            }

                            else {
                                if (x[1] <= 4.370000004768372) {
                                    if (x[5] <= -93.94499969482422) {
                                        return 59;
                                    }

                                    else {
                                        return 17;
                                    }
                                }

                                else {
                                    if (x[2] <= -177.0) {
                                        if (x[4] <= -76.5) {
                                            return 104;
                                        }

                                        else {
                                            return 48;
                                        }
                                    }

                                    else {
                                        return 10;
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
