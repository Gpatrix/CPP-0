/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:10:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 16:31:44 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string& new_name, int& new_grade);
		Bureaucrat(const Bureaucrat&);

		Bureaucrat&	operator=(const Bureaucrat&);


		void	signForm(Form&);

		void	incrementGrade(void);
		void	decrementGrade(void);

		std::string	getName(void) const;
		int			getGrade(void) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		~Bureaucrat(void);
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat&);