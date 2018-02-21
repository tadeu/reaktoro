// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright (C) 2014-2015 Allan Leal
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

// pybind11 includes
#include <pybind11/pybind11.h>
namespace py = pybind11;

// Reaktoro includes
#include <Reaktoro/Common/ChemicalScalar.hpp>
#include <Reaktoro/Common/ChemicalVector.hpp>
#include <Reaktoro/Common/ThermoScalar.hpp>
#include <Reaktoro/Common/ThermoVector.hpp>

namespace Reaktoro {

void exportThermoScalar(py::module& m)
{
    py::class_<ThermoScalar>(m, "ThermoScalar")
        .def(py::init<>())
        .def(py::init<double>())
        .def(py::init<double, double, double>())
        .def_readwrite("val", &ThermoScalar::val)
        .def_readwrite("ddT", &ThermoScalar::ddT)
        .def_readwrite("ddP", &ThermoScalar::ddP)
        ;
}

void exportThermoVector(py::module& m)
{
    py::class_<ThermoVector>(m, "ThermoVector")
        .def(py::init<>())
        .def(py::init<Index>())
        .def(py::init<Index, double>())
        .def(py::init<const Vector&, const Vector&, const Vector&>())
        .def_readwrite("val", &ThermoVector::val)
        .def_readwrite("ddT", &ThermoVector::ddT)
        .def_readwrite("ddP", &ThermoVector::ddP)
        ;
}

void exportChemicalScalar(py::module& m)
{
    py::class_<ChemicalScalar>(m, "ChemicalScalar")
        .def(py::init<>())
        .def(py::init<Index>())
        .def(py::init<Index, double>())
        .def(py::init<double, double, double, const Vector&>())
        .def_readwrite("val", &ChemicalScalar::val)
        .def_readwrite("ddT", &ChemicalScalar::ddT)
        .def_readwrite("ddP", &ChemicalScalar::ddP)
        .def_readwrite("ddn", &ChemicalScalar::ddn)
        ;
}

void exportChemicalVector(py::module& m)
{
    py::class_<ChemicalVector>(m, "ChemicalVector")
        .def(py::init<>())
        .def(py::init<Index>())
        .def(py::init<Index, Index>())
        .def(py::init<const Vector&, const Vector&, const Vector&, const Matrix&>())
        .def_readwrite("val", &ChemicalVector::val)
        .def_readwrite("ddT", &ChemicalVector::ddT)
        .def_readwrite("ddP", &ChemicalVector::ddP)
        .def_readwrite("ddn", &ChemicalVector::ddn)
        ;
}

void exportTemperature(py::module& m)
{
    py::class_<Temperature, ThermoScalar>(m, "Temperature")
        .def(py::init<>())
        .def(py::init<double>())
        ;
}

void exportPressure(py::module& m)
{
    py::class_<Pressure, ThermoScalar>(m, "Pressure")
        .def(py::init<>())
        .def(py::init<double>())
        ;
}

void exportAutoDiff(py::module& m)
{
    exportThermoScalar(m);
    exportThermoVector(m);
    exportChemicalScalar(m);
    exportChemicalVector(m);
    exportTemperature(m);
    exportPressure(m);
}

} // namespace Reaktoro

