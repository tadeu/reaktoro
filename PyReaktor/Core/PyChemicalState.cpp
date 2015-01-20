// Reaktor is a C++ library for computational reaction modelling.
//
// Copyright (C) 2014 Allan Leal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "PyChemicalState.hpp"

// Boost includes
#include <boost/python.hpp>
namespace py = boost::python;

// Reaktor includes
#include <Reaktor/Core/ChemicalSystem.hpp>
#include <Reaktor/Core/ChemicalState.hpp>

namespace Reaktor {

auto export_ChemicalState() -> void
{
    auto setTemperature1 = static_cast<void(ChemicalState::*)(double)>(&ChemicalState::setTemperature);
    auto setTemperature2 = static_cast<void(ChemicalState::*)(double, std::string)>(&ChemicalState::setTemperature);

    auto setPressure1 = static_cast<void(ChemicalState::*)(double)>(&ChemicalState::setPressure);
    auto setPressure2 = static_cast<void(ChemicalState::*)(double, std::string)>(&ChemicalState::setPressure);

    auto setSpeciesAmounts1 = static_cast<void(ChemicalState::*)(double)>(&ChemicalState::setSpeciesAmounts);
    auto setSpeciesAmounts2 = static_cast<void(ChemicalState::*)(const Vector&)>(&ChemicalState::setSpeciesAmounts);

    auto setSpeciesAmount1 = static_cast<void(ChemicalState::*)(Index, double)>(&ChemicalState::setSpeciesAmount);
    auto setSpeciesAmount2 = static_cast<void(ChemicalState::*)(std::string, double)>(&ChemicalState::setSpeciesAmount);
    auto setSpeciesAmount3 = static_cast<void(ChemicalState::*)(Index, double, std::string)>(&ChemicalState::setSpeciesAmount);
    auto setSpeciesAmount4 = static_cast<void(ChemicalState::*)(std::string, double, std::string)>(&ChemicalState::setSpeciesAmount);

    auto speciesAmount1 = static_cast<double(ChemicalState::*)(Index) const>(&ChemicalState::speciesAmount);
    auto speciesAmount2 = static_cast<double(ChemicalState::*)(std::string) const>(&ChemicalState::speciesAmount);
    auto speciesAmount3 = static_cast<double(ChemicalState::*)(Index, std::string) const>(&ChemicalState::speciesAmount);
    auto speciesAmount4 = static_cast<double(ChemicalState::*)(std::string, std::string) const>(&ChemicalState::speciesAmount);

    auto speciesAmountsInPhase1 = static_cast<Vector(ChemicalState::*)(Index) const>(&ChemicalState::speciesAmountsInPhase);
    auto speciesAmountsInPhase2 = static_cast<Vector(ChemicalState::*)(std::string) const>(&ChemicalState::speciesAmountsInPhase);

    auto elementAmount1 = static_cast<double(ChemicalState::*)(Index) const>(&ChemicalState::elementAmount);
    auto elementAmount2 = static_cast<double(ChemicalState::*)(std::string) const>(&ChemicalState::elementAmount);
    auto elementAmount3 = static_cast<double(ChemicalState::*)(Index, std::string) const>(&ChemicalState::elementAmount);
    auto elementAmount4 = static_cast<double(ChemicalState::*)(std::string, std::string) const>(&ChemicalState::elementAmount);

    auto elementAmountInPhase1 = static_cast<double(ChemicalState::*)(Index, Index) const>(&ChemicalState::elementAmountInPhase);
    auto elementAmountInPhase2 = static_cast<double(ChemicalState::*)(std::string, std::string) const>(&ChemicalState::elementAmountInPhase);
    auto elementAmountInPhase3 = static_cast<double(ChemicalState::*)(Index, Index, std::string) const>(&ChemicalState::elementAmountInPhase);
    auto elementAmountInPhase4 = static_cast<double(ChemicalState::*)(std::string, std::string, std::string) const>(&ChemicalState::elementAmountInPhase);

    py::class_<ChemicalState>("ChemicalState", py::no_init)
        .def(py::init<const ChemicalSystem&>())
        .def("setTemperature", setTemperature1)
        .def("setTemperature", setTemperature2)
        .def("setPressure", setPressure1)
        .def("setPressure", setPressure2)
        .def("setSpeciesAmounts", setSpeciesAmounts1)
        .def("setSpeciesAmounts", setSpeciesAmounts2)
        .def("setSpeciesAmount", setSpeciesAmount1)
        .def("setSpeciesAmount", setSpeciesAmount2)
        .def("setSpeciesAmount", setSpeciesAmount3)
        .def("setSpeciesAmount", setSpeciesAmount4)
        .def("setChargePotential", &ChemicalState::setChargePotential)
        .def("setElementPotentials", &ChemicalState::setElementPotentials)
        .def("setSpeciesPotentials", &ChemicalState::setSpeciesPotentials)
        .def("system", &ChemicalState::system, py::return_value_policy<py::copy_const_reference>())
        .def("temperature", &ChemicalState::temperature)
        .def("pressure", &ChemicalState::pressure)
        .def("speciesAmounts", &ChemicalState::speciesAmounts, py::return_value_policy<py::copy_const_reference>())
        .def("chargePotential", &ChemicalState::chargePotential)
        .def("elementPotentials", &ChemicalState::elementPotentials, py::return_value_policy<py::copy_const_reference>())
        .def("speciesPotentials", &ChemicalState::speciesPotentials, py::return_value_policy<py::copy_const_reference>())
        .def("speciesAmount", speciesAmount1)
        .def("speciesAmount", speciesAmount2)
        .def("speciesAmount", speciesAmount3)
        .def("speciesAmount", speciesAmount4)
        .def("speciesAmountsInPhase", speciesAmountsInPhase1)
        .def("speciesAmountsInPhase", speciesAmountsInPhase2)
        .def("elementAmounts", &ChemicalState::elementAmounts)
        .def("elementAmount", elementAmount1)
        .def("elementAmount", elementAmount2)
        .def("elementAmount", elementAmount3)
        .def("elementAmount", elementAmount4)
        .def("elementAmountInPhase", elementAmountInPhase1)
        .def("elementAmountInPhase", elementAmountInPhase2)
        .def("elementAmountInPhase", elementAmountInPhase3)
        .def("elementAmountInPhase", elementAmountInPhase4)
        ;
}

} //space Reaktor
