/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <string>
#include <vector>

#include "Eigen/Dense"

#include "modules/common/macro.h"
#include "modules/prediction/network/net_layer.h"
#include "modules/prediction/network/net_model.h"

#ifndef MODULES_PREDICTION_NETWORK_RNN_MODEL_RNN_MODEL_H_
#define MODULES_PREDICTION_NETWORK_RNN_MODEL_RNN_MODEL_H_

/**
 * @namespace apollo::prediction::network
 * @brief apollo::prediction::network
 */
namespace apollo {
namespace prediction {
namespace network {

/**
 * @class RnnModel
 * @brief RnnModel is a derived class from NetModel, it has a specific layers structure.
 */
class RnnModel : public NetModel {
 public:
  /**
   * @brief Compute the model output from inputs according to a defined layers' flow
   * @param Inputs to the network
   * @param Output of the network will be returned
   */
  virtual void Run(const std::vector<Eigen::MatrixXf>& inputs,
                   Eigen::MatrixXf* output) const;

  /**
   * @brief Set the internal state of a network model
   * @param A specified internal state in a vector of Eigen::MatrixXf
   */
  virtual void SetState(const std::vector<Eigen::MatrixXf>& states);

  /**
   * @brief Access to the internal state of a network model
   * @return Internal state in a vector of Eigen::MatrixXf of the model
   */
  virtual void State(std::vector<Eigen::MatrixXf>* states) const;

  /**
   * @brief Set the internal state of a model
   * @param A specified internal state in a vector of Eigen::MatrixXf
   */
  virtual void ResetState() const;

  DECLARE_SINGLETON(RnnModel);
};

}  // namespace network
}  // namespace prediction
}  // namespace apollo

#endif  // MODULES_PREDICTION_NETWORK_RNN_MODEL_RNN_MODEL_H_
