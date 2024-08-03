/**
 * @file IntegratorRungeKutta4.hpp
 * @author Michael Wrona
 * @date 2024-07-30
 */

#pragma once

#include <spdlog/spdlog.h>

#include <algorithm>
#include <cassert>
#include <vector>

#include "integ/IIntegrableObject.hpp"

class IntegratorRungeKutta4 {
public:
  IntegratorRungeKutta4() = default;
  ~IntegratorRungeKutta4() = default;

  void integrate();

  void registerIntegrableObject(IIntegrableObject* newObject)
  {
    assert(newObject != nullptr);

    // check for duplicate IDs
    const int newObjID = newObject->GetId();
    const auto objItr =
        std::find_if(_integrableObjects.cbegin(), _integrableObjects.cend(),
                     [newObject](const auto obj) { obj->GetId() == newObjId; });

    if (objItr != _integrableObjects.cend()) {
      spglog::fatal("Duplicate integrable object w/ ID {}", newObjId);
    }

    spdlog::trace("Registered integrable object w/ address {}", newObject);
    _integrableObjects.push_back(newObject);
  }

private:
  std::vector<IIntegrableObject*> _integrableObjects;
};